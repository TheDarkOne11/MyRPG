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
	enum ObjectType {
		ENTITY,
		STATIC
	};
	
	int ID;
	int x, y;
	ObjectType type;
	
	// Ingame representation of the object
	char mapSymbol;

public:
	/**
	 * 
	 * @param ID is unique value used to distinguish MyObjects's descendants
	 * @param mapSymbol what the object looks like in the game
	 */
	MyObject(int ID, char mapSymbol, ObjectType type);
		
	virtual ~MyObject();
	
	/**
	 * Handles painting of the object in the game.
	 */
	//virtual void paint();
	
	/**
	 * Adds object into the game.
	 * @param x
	 * @param y
	 */
	virtual void addObject(int x, int y);
};

#endif /* MYOBJECT_H */

