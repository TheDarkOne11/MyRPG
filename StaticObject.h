/* 
 * File:   Static_Object.h
 * Author: petr
 *
 * Created on May 8, 2017, 8:57 PM
 */

#ifndef STATIC_OBJECT_H
#define STATIC_OBJECT_H

#include "MyObject.h"

/**
 * Super class for static objects (walls, chests, doors...)
 */
class StaticObject : public MyObject {
public:
	/**
	 * This constructor is used for setting up "template" instances of derived classes.
	 * @param mapSymbol what the object looks like in the game
	 */
	StaticObject(int ID, char mapSymbol, bool isPassable);
	
	/**
	 * This constructor is used for cloning "templates" of derived classes.
	 * @param temp is a "template" instance of the derived class.
	 */
	StaticObject(const StaticObject* temp);
	
private:
};

#endif /* STATIC_OBJECT_H */

