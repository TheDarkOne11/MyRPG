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
	StaticObject(char mapSymbol);
	
private:
	static int lastID;
};

#endif /* STATIC_OBJECT_H */

