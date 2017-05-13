#include "StaticObject.h"

int StaticObject::lastID = 0;

StaticObject::StaticObject(char mapSymbol) 
					: MyObject(lastID, mapSymbol, MyObject::STATIC)
{
	lastID++;
}

StaticObject::StaticObject(const StaticObject* tmp) 
					: MyObject(lastID, tmp->mapSymbol, MyObject::STATIC)
{
}