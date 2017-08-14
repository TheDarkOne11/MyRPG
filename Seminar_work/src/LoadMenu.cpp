#include "LoadMenu.h"

LoadMenu::LoadMenu() : isUpdated(false) {
	fileNamesMenu.setHead("Saved games");
}

void LoadMenu::reloadChoices() {
	std::ifstream file(Info::pathNamesSaves);
	std::string s;
	int i = 0;
	ChoiceVect choices;	
	
	if(!file.is_open()) {
		throw "LoadMenu: File " + Info::pathNamesSaves + " not opened.";
	}
	
	// Read fileNames of saves. Store them in vector, init choices.
	while(std::getline(file, s)) {
		choices.push_back( std::make_pair(s, i) );
		vect_FileNames.push_back(s);
		i++;
	}
	fileNamesMenu.setChoices(choices);
	
	file.close();
}


int LoadMenu::update(std::string& fileName) {
	int retVal = fileNamesMenu.update();
	
	if(!isUpdated) {
		reloadChoices();
	}
	
	if(retVal != -1) {
		// FileName chosen
		fileName = vect_FileNames.at(retVal);
		isUpdated = false;
		return 1;
	}
	
	switch(UserInput::getPressedKey()) {
		case(UserInput::K_ESC):
			isUpdated = false;
			return 0;
	}
	
	return -1;
}

void LoadMenu::paint(Screen* screen) {
	fileNamesMenu.paint(screen);
}
