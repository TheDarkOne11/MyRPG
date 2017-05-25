#include "Menu.h"
#include "Screen.h"

Menu::Menu() : head(""), headExists(false), currChoice(0), offsetY(0), offsetX(0) {
}

Menu::Menu(std::string head) : head(head), headExists(true), currChoice(0), offsetY(0), offsetX(0) {
}

void Menu::paint(Screen* screen) {
	std::pair<int, int> p = screen->getCurrDimensions();
	int currY = p.first/2 + offsetY - choices.size();
	int currX = p.second/2 + offsetX;
	int firstIndex = 0;
	
	/*
	 * When choices are longer than screen, this makes it possible to see all of them.
	 * 'Scrolling' to the bottom of the choices vector.
	 */
	if(currY < 2) {
		currY = 2;
		firstIndex = currChoice;
	}
	
	// Paint head if it exists
	if(headExists) {
		attron(A_BOLD);
		mvwprintw(screen->getCurrScreen(), currY - 2, currX - head.size()/2, head.c_str());
		attroff(A_BOLD);
	}
	
	// Paint choices
	int i = firstIndex;
	for(auto it = choices.begin() + firstIndex; it != choices.end(); it++) {
		std::string currString = it->first;
		
		if(i == currChoice) {
			// Highlight current choice
			wattron(screen->getCurrScreen(), A_REVERSE);
			mvwprintw(screen->getCurrScreen(), currY, currX - currString.size()/2, currString.c_str());
			wattroff(screen->getCurrScreen(), A_REVERSE);
		} else {
			mvwprintw(screen->getCurrScreen(), currY, currX - currString.size()/2, currString.c_str());
		}
		
		i++;
		currY += 2;
	}
}

int Menu::update() {
	int tmp;
	
	if(choices.empty()) {
		return -1;
	}
	
	// Traverse choices
	switch(UserInput::getPressedKey()) {
		case(UserInput::K_UP):
			currChoice = (currChoice <= 0) ? choices.size() : currChoice;
			currChoice--;
			break;
		case(UserInput::K_DOWN):
			currChoice = (currChoice + 1) % choices.size();
			break;
		case(UserInput::K_ENTER):
			// Last picked choice was chosen
			tmp = currChoice;
			currChoice = 0;
			return choices[tmp].second;
	}
	
	return -1;
}


void Menu::setChoices(ChoiceVect& choices) {
	this->choices.clear();
	
	for(auto iter = choices.begin(); iter != choices.end(); iter++) {
		this->choices.push_back(*iter);
	}
}

void Menu::setHead(std::string head) {
	this->head = head;
	headExists = true;
}

int Menu::getCurrentChoice() {
	return choices.at(currChoice).second;
}

void Menu::setScreenOffset(const int y, const int x) {
	offsetY = y;
	offsetX = x;
}
