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
#include "Attributes.h"

/**
 * Class stores initialized "template" instances of all MyObject and Item classes.
 * Class provides copies of these "templates" to other classes.
 */
class Handler {
public:	
	/**
	 * Deletes all templates.
	 */
	static void clear();
	
	/**
	 * Class initialization.
	 */
	static void init();
	
	/**
	 * @param type is a type of the Item.
	 * @param ID is an ID of the Item.
	 * @return Item of specified ID and type.
	 */
	static Item* getItem(const Item::ItemType type, const int ID);
	
	/**
	 * @param type
	 * @return Random Item of specified type.
	 */
	static Item* getItem(const Item::ItemType type);
	
	/**
	 * Finds the MyObject subclass using mapSymbol.
	 * @param mapSymbol is the unique symbol each MyObject class has.
	 * @return Copy of the MyObject subclass.
	 */
	static MyObject* getMyObject(const char mapSymbol);
	
	/**
	 * Finds the MyObject subclass using group and ID.
	 * Used when adding 
	 * @param ObjectGroup
	 * @param ID
	 * @return Copy of the MyObject subclass.
	 */
	static MyObject* getMyObject(const MyObject::ObjectGroup, const int ID);
	
	/**
	 * Returns random member of ObjectGroup.
	 * Used when adding MyObject subclasses into the game map (like enemies...)
	 * @param ObjectGroup
	 * @return Copy of the MyObject subclass.
	 */
	static MyObject* getMyObject(const MyObject::ObjectGroup);
		
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

