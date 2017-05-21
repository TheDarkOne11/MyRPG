#ifndef MYOBJECT_H
#define MYOBJECT_H

#include <ncurses.h>
#include <iostream>
#include <vector>
#include <list>
#include "Info.h"
#include "Screen.h"
#include "Item.h"

/**
 * Super class of all entities and static objects that can be placed in the game map.
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
	MyObject(int ID, char mapSymbol, ObjectGroup type, bool isPassable, std::string name);

	virtual ~MyObject();

	/**
	 * Paints this MyObject on the screen at the specified coordinates.
	 * @param y
	 * @param x
	 */
	virtual void paint(Screen* screen, const int y, const int x);

	/**
	 * Adds this MyObject into the game.
	 * Used when adding into the map randomly.
	 * @param x
	 * @param y
	 * @param removeFormer true if we want to delete former MyObject on these coordinates
	 */
	virtual void addToMap(LevelMap& levelMap, int y, 
							int x, bool removeFormer);
	
	virtual MyObject* clone() const = 0;
	
	virtual int getID() const;

	virtual int getX() const;
	
	virtual void setCoordinates(int y, int x);

	virtual int getY() const;
	
	virtual bool getPassable() const;

	virtual ObjectGroup getGroup() const;
	
	virtual char getMapSymbol() const;
	
	virtual std::string getName() const;
	
	virtual InvList& getInventory();

protected:
	/**
	 * ID is unique inside one ObjectGroup
	 */
	int ID;
	int x, y;

	/**
	 * Default representation of MyObject subclass inside levelMap.
	 */
	char mapSymbol;

	ObjectGroup group;
	
	/**
	 * true if Entity can move to this MyObject's position
	 */
	bool isPassable;
	
	std::string name;
	
	/**
	 * All Items this MyObject currently has.
	 */
	InvList inventory;
};

#endif /* MYOBJECT_H */

