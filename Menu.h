/* 
 * File:   Menu.h
 * Author: petr
 *
 * Created on May 13, 2017, 9:11 PM
 */

#ifndef MENU_H
#define MENU_H

#include <vector>
#include <iostream>
#include <ncurses.h>
#include "ConfigClass.h"
#include "UserInput.h"

#define ChoiceList std::vector< std::pair<std::string, int> >

/**
 * Class handles painting and updates of simple menus.
 */
class Menu {
public:
	Menu();
	
	void setChoices(ChoiceList choices);
	
	void paint();
	
	/**
	 * 
	 * @return int (enum) associated with choice that was chosen. Else returns -1.
	 */
	int update();
	
private:
	std::string head;
	ChoiceList choices;
	int currChoice;
};

#endif /* MENU_H */

