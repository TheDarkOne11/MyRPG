/* 
 * File:   Screen.h
 * Author: petr
 *
 * Created on May 16, 2017, 4:47 PM
 */

#ifndef SCREEN_H
#define SCREEN_H

#include <ncurses.h>

class Screen {
public:
	const int statsScreenHeight = 5;
	
	enum ScreenTypes {
		STANDARD = 0,
		GAME = 1,
		STATS = 2
	};
	
	Screen();
	~Screen();
	
	void sClear();
	
	void sRefresh();
	
	WINDOW* setCurrScreen(ScreenTypes type);
	
	WINDOW* getCurrScreen();
	
private:
	int maxHeight, maxWidth;
	
	/**
	 * All types of screen
	 */
	std::vector<WINDOW*> vect_screens;
	
	/**
	 * Screen used currently
	 */
	WINDOW* currScreen;
	
	void addScreen(WINDOW* screen);
};

#endif /* SCREEN_H */

