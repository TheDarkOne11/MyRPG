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
class Static_Object : public MyObject {
private:
	static int lastID;

public:
	Static_Object(char mapSymbol);
};

#endif /* STATIC_OBJECT_H */

