#ifndef USERINPUT_H
#define USERINPUT_H

#include <ncurses.h>

/**
 * Handles input from keyboard.
 */
class UserInput {
public:
	const static int K_ENTER = 10;			///< ENTER key
	const static int K_ATTACK= 'q';
	const static int K_SWAP= 's';
	const static int K_ESC = 27;			///< ESCAPE key
	const static int K_UP = KEY_UP;
	const static int K_DOWN = KEY_DOWN;
	const static int K_LEFT = KEY_LEFT;
	const static int K_RIGHT = KEY_RIGHT;

	static void update();
	
	static int getPressedKey();
private:
	static int pressedKey;
};

#endif /* USERINPUT_H */

