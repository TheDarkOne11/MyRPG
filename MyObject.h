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
	 * @param ID is unique value used to distinguish MyObjects's subclasses
	 * @param mapSymbol what the object looks like in the game
	 */
	MyObject(int ID, char mapSymbol, ObjectGroup type);

	virtual ~MyObject();

	/**
	 * Paints the object at its coordinates.
	 */
	virtual void paint();
	
	/**
	 * Paints the object on the screen at the specified coordinates.
	 * @param y
	 * @param x
	 */
	virtual void paint(const int y, const int x);

	/**
	 * Adds object into the game.
	 * @param x
	 * @param y
	 */
	virtual void addToMap(int y, int x);
	
	virtual MyObject* clone() const = 0;

	virtual int getX() const;

	virtual int getY() const;

	virtual ObjectGroup getGroup() const;
	
	virtual char getMapSymbol() const;

protected:
	int ID;
	int x, y;

	// Ingame representation of the object
	char mapSymbol;

	ObjectGroup group;
};

#endif /* MYOBJECT_H */

