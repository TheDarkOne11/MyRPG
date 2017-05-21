#ifndef MYOBJECTDESCENDANTS_H
#define MYOBJECTDESCENDANTS_H

#include <vector>
#include <map>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <utility>
#include "MyObject.h"
#include "Player.h"
#include "Info.h"
#include "StaticObject.h"
#include "Enemy.h"
#include "Item.h"

/**
 * Class has some important constants for the game.
 * Class stores initialized "template" instances of all MyObject and Item classes.
 * Class provides copies of these "templates" to other classes.
 */
class Handler {
public:	
	static void clear();
	
	/**
	 * Class initialization.
	 */
	static void init();
	
	static Item* getItem(const int ID, const Item::ItemType type);
	
	static Item* getItem(const Item::ItemType);
		
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
	 * Map of all types of MyObject template instances.
	 * Divided into groups by ObjectType key.
	 */
	static std::map<MyObject::ObjectGroup, std::vector<MyObject*>> map_MyObjectsTypes;
	
	/**
	 * Map of all types of Item template instances.
	 * Divided into groups by ItemType key.
	 */
	static std::map<Item::ItemType, std::vector<Item*>> map_ItemTypes;
	static Player* player;
	
	/**
	 * Stores new object into the map.
	 * @param object is the object which we want to store.
	 */
	static void addObject(MyObject* object);
	
	/**
	 * Stores new item into the map.
	 * @param item is the object which we want to store.
	 */
	static void addItem(Item* item);
};

#endif /* MYOBJECTDESCENDANTS_H */

