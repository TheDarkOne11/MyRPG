/* 
 * File:   UserInput.h
 * Author: petr
 *
 * Created on May 10, 2017, 8:35 PM
 */

#ifndef USERINPUT_H
#define USERINPUT_H

#include <ncurses.h>

/**
 * Handles input from keyboard.
 */
class UserInput {
public:
	UserInput();
	
	void update();
	
	static int getPressedKey();
private:
	static int pressedKey;
};

#endif /* USERINPUT_H */

