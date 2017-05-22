#ifndef MENU_H
#define MENU_H

#include <vector>
#include <iostream>
#include <ncurses.h>
#include "UserInput.h"
#include "Info.h"
#include "Screen.h"

/**
 * Class handles painting and updates of simple menus.
 */
class Menu {
public:
	Menu();
	
	Menu(std::string head);
	
	void setChoices(ChoiceVect& choices);
	
	void setScreenOffset(const int y, const int x);
	
	void setHead(std::string head);
	
	void paint(Screen* screen);
	
	/**
	 * Update menu, traverse choices.
	 * @return int (enum) associated with choice that was chosen. Else returns -1.
	 */
	int update();
	
	/**
	 * @return Currently chosen value;
	 */
	int getCurrentChoice();
	
private:
	std::string head;
	bool headExists;
	ChoiceVect choices;
	int currChoice;
	int offsetY, offsetX;
};

#endif /* MENU_H */

