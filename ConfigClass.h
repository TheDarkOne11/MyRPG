/* 
 * File:   MyObjectDescendants.h
 * Author: petr
 *
 * Created on May 9, 2017, 5:11 PM
 */

#ifndef MYOBJECTDESCENDANTS_H
#define MYOBJECTDESCENDANTS_H

#include <vector>
#include <map>
#include <iostream>
#include <utility>
#include "MyObject.h"
#include "Wall.h"
#include "Player.h"

/**
 * Class has some important constants for the game.
 * All types of MyObject subclasses that can be placed in the game are initialized here. (Wall, Player..)
 * Class provides copies of these subclasses.
 */
class ConfigClass {
public:
	ConfigClass();
	~ConfigClass();
	
	static MyObject* getMyObject(const char mapSymbol);
	static MyObject* getMyObject(const MyObject::ObjectGroup, const int ID);
	static MyObject* getMyObject(const MyObject::ObjectGroup);
	static Player* getPlayer();
	
private:
	/**
	 * Map of all types of MyObject subclasses.
	 * Divided into groups by ObjectType key.
	 */
	std::map<MyObject::ObjectGroup, std::vector<MyObject*>> mapMyObjectsTypes;
	static Player* player;
	
	/**
	 * Class initialization.
	 */
	void init();
	
	/**
	 * Stores new object into the map.
	 * @param object is the object which we want to store.
	 */
	void addObject(MyObject* object);
};

#endif /* MYOBJECTDESCENDANTS_H */

