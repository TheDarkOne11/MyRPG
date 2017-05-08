/* 
 * File:   MyObject.h
 * Author: petr
 *
 * Created on May 8, 2017, 3:39 PM
 */

#ifndef MYOBJECT_H
#define MYOBJECT_H

#include <ncurses.h>
#include <iostream>

/**
 * Super class of all objects in the game (Walls, Player, Enemies...)
 */
class MyObject {
protected:
	int ID;
	int x, y;
	
	// Ingame representation of the object
	char mapSymbol;

public:
	/**
	 * 
	 * @param ID is unique value used to distinguish MyObjects's descendants
	 * @param x is ingame x position
	 * @param y is ingame y position
	 * @param mapSymbol what the object looks like in the game
	 */
	MyObject(int ID, int x, int y, char mapSymbol);
		
	virtual ~MyObject();
	
	/**
	 * Handles painting of the object in the game.
	 */
	//virtual void paint();
};

#endif /* MYOBJECT_H */

