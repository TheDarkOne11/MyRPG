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
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <utility>
#include "MyObject.h"
#include "Wall.h"
#include "Player.h"
#include "Floor.h"
#include "Mob.h"
#include "Door.h"
#include "Info.h"

#define DefiningPair std::pair<int, MyObject::ObjectGroup>

/**
 * Class has some important constants for the game.
 * All types of MyObject subclasses that can be placed in the game are initialized here. (Wall, Player..)
 * These initialized subclass serve as "templates", their copies are provided outside ConfigClass.
 */
class Handler {
public:	
	~Handler();
	
	/**
	 * Class initialization.
	 */
	static void init();
		
	/**
	 * Finds the MyObject subclass using mapSymbol.
	 * @param mapSymbol is the unique symbol each MyObject class has.
	 * @return Pair<ID, ObjectGroup> of the MyObject subclass
	 */
	static DefiningPair getMyObjectID(const char mapSymbol);
	
	/**
	 * Finds the MyObject subclass using mapSymbol.
	 * @param mapSymbol is the unique symbol each MyObject class has.
	 * @return copy of the MyObject subclass.
	 */
	static MyObject* getMyObject(const char mapSymbol);
	
	/**
	 * Finds the MyObject subclass using group and ID.
	 * Used when adding 
	 * @param ObjectGroup
	 * @param ID
	 * @return copy of the MyObject subclass.
	 */
	static MyObject* getMyObject(const MyObject::ObjectGroup, const int ID);
	
	/**
	 * Returns random member of ObjectGroup.
	 * Used when adding MyObject subclasses into the game map (like enemies...)
	 * @param ObjectGroup
	 * @return copy of the MyObject subclass.
	 */
	static MyObject* getMyObject(const MyObject::ObjectGroup);
	
	/**
	 * Returns a copy of player subclass.
	 * @return player
	 */
	static Player* getPlayer();
		
private:
	/**
	 * Map of all types of MyObject subclasses.
	 * Divided into groups by ObjectType key.
	 */
	static std::map<MyObject::ObjectGroup, std::vector<MyObject*>> map_MyObjectsTypes;
	static Player* player;
	
	/**
	 * Stores new object into the map.
	 * @param object is the object which we want to store.
	 */
	static void addObject(MyObject* object);
};

#endif /* MYOBJECTDESCENDANTS_H */

