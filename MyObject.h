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
		ENTITY,
		STATIC
	};

	/**
	 * 
	 * @param ID is unique value used to distinguish MyObjects's subclasses
	 * @param mapSymbol what the object looks like in the game
	 */
	MyObject(int ID, char mapSymbol, ObjectGroup type, bool isPassable);

	virtual ~MyObject();

	/**
	 * Paints this MyObject on the screen at the specified coordinates.
	 * @param y
	 * @param x
	 */
	virtual void paint(const int y, const int x);
	
	/**
	 * Updates MyObject.
	 * @param y
	 * @param x
	 */
	virtual void update();

	/**
	 * Adds this MyObject into the game.
	 * @param x
	 * @param y
	 */
	virtual void addToMap(int y, int x);
	
	virtual MyObject* clone() const = 0;
	
	virtual int getID() const;

	virtual int getX() const;

	virtual int getY() const;
	
	virtual bool getPassable() const;

	virtual ObjectGroup getGroup() const;
	
	virtual char getMapSymbol() const;

protected:
	/**
	 * ID unique to this MyObject's ObjectGroup
	 */
	int ID;
	int x, y;
	
	/**
	 * true if Entity can move to this MyObject's position
	 */
	bool isPassable;

	/**
	 * Ingame representation of the object.
	 */
	char mapSymbol;

	ObjectGroup group;
};

#endif /* MYOBJECT_H */

