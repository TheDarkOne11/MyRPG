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
public:

	enum ObjectGroup {
		ENTITY_ENEMY,
		STATIC
	};

	/**
	 * 
	 * @param ID is unique value used to distinguish MyObjects's descendants
	 * @param mapSymbol what the object looks like in the game
	 */
	MyObject(int ID, char mapSymbol, ObjectGroup type);

	virtual ~MyObject();

	/**
	 * Handles painting of the object in the game.
	 */
	virtual void paint();

	/**
	 * Adds object into the game.
	 * @param x
	 * @param y
	 */
	virtual void addObject(int y, int x);

	int getX();

	int getY();

	ObjectGroup getGroup();

protected:
	int ID;
	int x, y;

	// Ingame representation of the object
	char mapSymbol;

	ObjectGroup group;
};

#endif /* MYOBJECT_H */

