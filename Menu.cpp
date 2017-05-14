#include "Menu.h"

Menu::Menu() : head(""), headExists(false), currChoice(0) {
}

Menu::Menu(std::string head) : head(head), headExists(true), currChoice(0) {
}

void Menu::paint() {
	int currX = Info::getWidth()/2;
	int currY = Info::getHeight()/2;
	int i = 0;
	
	// Paint head if it exists
	if(headExists) {
		attron(A_BOLD);
		mvprintw(currY - 2, currX - head.size()/2, head.c_str());
		attroff(A_BOLD);
	}
	
	// Paint choices
	for(auto it = choices.begin(); it != choices.end(); it++) {
		std::string currString = it->first;
		
		if(i == currChoice) {
			attron(A_REVERSE);
			mvprintw(currY, currX - currString.size()/2, currString.c_str());
			attroff(A_REVERSE);
		} else {
			mvprintw(currY, currX - currString.size()/2, currString.c_str());
		}
		
		i++;
		currY += 2*i;
	}
}

int Menu::update() {
	// Traverse choices
	switch(UserInput::getPressedKey()) {
		case(UserInput::K_UP):
			currChoice = (currChoice - 1) % choices.size();
			break;
		case(UserInput::K_DOWN):
			currChoice = (currChoice + 1) % choices.size();
			break;
		case(UserInput::K_ENTER):
			// Last picked choice was chosen
			return choices[currChoice].second;
			break;
	}
	
	return -1;
}


void Menu::setChoices(ChoiceList choices) {
	this->choices.clear();
	
	for(auto iter = choices.begin(); iter != choices.end(); iter++) {
		this->choices.push_back(*iter);
	}
}

void Menu::setHead(std::string head) {
	this->head = head;
	headExists = true;
}
