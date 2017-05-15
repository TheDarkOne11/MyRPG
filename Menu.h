#ifndef MENU_H
#define MENU_H

#include <vector>
#include <iostream>
#include <ncurses.h>
#include "UserInput.h"
#include "Info.h"

/**
 * Class handles painting and updates of simple menus.
 */
class Menu {
public:
	Menu();
	
	Menu(std::string head);
	
	void setChoices(ChoiceVect choices);
	
	void setHead(std::string head);
	
	void paint();
	
	/**
	 * 
	 * @return int (enum) associated with choice that was chosen. Else returns -1.
	 */
	int update();
	
private:
	std::string head;
	bool headExists;
	ChoiceVect choices;
	int currChoice;
};

#endif /* MENU_H */

