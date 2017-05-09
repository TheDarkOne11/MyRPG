#include "StaticObject.h"

int Static_Object::lastID = 0;

Static_Object::Static_Object(char mapSymbol) 
					: MyObject(lastID, mapSymbol, MyObject::STATIC)
{
	lastID++;
}

