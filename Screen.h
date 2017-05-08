/* 
 * File:   Screen.h
 * Author: petr
 *
 * Created on May 8, 2017, 5:32 PM
 */

#ifndef SCREEN_H
#define SCREEN_H

#include <ncurses.h>
#include <iostream>

/**
 * Takes care of screen updates and painting.
 */
class Screen {
private:
	

public:
	Screen();
	~Screen();
	
	/**
	 * Updates screen.
	 */
	void update();
	
	/**
	 * Paint screen.
	 */
	void paint();

};

#endif /* SCREEN_H */

