#ifndef MENU_H
#define MENU_H

#include <vector>
#include <iostream>
#include <ncurses.h>
#include "UserInput.h"
#include "Info.h"
#include "Screen.h"

/**
 * Class handles painting and updates of simple menus - list of choices, each can be picked.
 * Used as a base of more specialized menus.
 */
class Menu {
public:
	Menu();
	
	Menu(std::string head);
	
	/**
	 * Set which choices menu has.
	 * @param choices
	 */
	void setChoices(ChoiceVect& choices);
	
	/**
	 * Set screen offset from the middle.
	 * @param y is Y-offset from the middle.
	 * @param x is X-offset from the middle.
	 */
	void setScreenOffset(const int y, const int x);
	
	/**
	 * Set new head of the menu.
	 * @param head
	 */
	void setHead(std::string head);
	
	/**
	 * Paints menu in the currently selected window.
	 * Enables "scrolling" through choices if they are too long.
	 * @param screen
	 */
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
	std::string head;		///< Head of the menu.
	bool headExists;		///< True if a head exists
	ChoiceVect choices;		///< Vector of all choices with int values, which are returned when choice is picked
	int currChoice;			///< Index of currently selected choice.
	int offsetY, offsetX;
};

#endif /* MENU_H */

