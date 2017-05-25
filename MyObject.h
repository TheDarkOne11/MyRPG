#ifndef MYOBJECT_H
#define MYOBJECT_H

#include <ncurses.h>
#include <iostream>
#include <vector>
#include <list>
#include <fstream>
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
	 * @param ID is unique in the MyObject's group.
	 * @param mapSymbol is the symbol used in level map.
	 * @param group
	 * @param isPassable is true if Entity can move into this MyObjects position
	 * @param name
	 */
	MyObject(int ID, char mapSymbol, ObjectGroup group, bool isPassable, std::string name);

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
	
	/**
	 * Returns a clone derived instance of the current MyObject.
	 * @return Clone of more derived instance of MyObject.
	 */
	virtual MyObject* clone() const = 0;
	
	/**
	 * Save this MyObject into the file.
	 * @param file is the stream we write info to.
	 */
	virtual void save(std::ofstream& file) const;
	
	/**
	 * Load this MyObject from the file.
	 * @param file is the stream we get info from.
	 */
	virtual void load(std::ifstream& file);
	
	virtual int getID() const;
	
	virtual void setCoordinates(int y, int x);
	
	virtual int getX() const;

	virtual int getY() const;
	
	virtual bool getPassable() const;

	virtual ObjectGroup getGroup() const;
	
	virtual char getMapSymbol() const;
	
	virtual std::string getName() const;
	
	/**
	 * Provide MyObject's inventory for Item manipulations.
	 * @return Reference to this MyObject's inventory.
	 */
	virtual InvList& getInventory();

protected:
	int ID;				///< ID is unique inside one ObjectGroup.
	int y;				///< Y-coordinate of this MyObject in the map.
	int x;				///< X-coordinate of this MyObject in the map.
	char mapSymbol;		///< Default representation of MyObject subclass inside levelMap.
	ObjectGroup group;	
	bool isPassable;	///< True if Entity can move to this MyObject's position.
	std::string name;	///< Name of this MyObject.
	InvList inventory;	///< All Items this MyObject currently has.
};

#endif /* MYOBJECT_H */

