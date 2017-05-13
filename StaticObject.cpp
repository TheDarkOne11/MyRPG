#include "StaticObject.h"

int StaticObject::lastID = 0;

StaticObject::StaticObject(char mapSymbol, bool isPassable) 
					: MyObject(lastID, mapSymbol, MyObject::STATIC, isPassable)
{
	lastID++;
}

StaticObject::StaticObject(const StaticObject* tmp) 
					: MyObject(lastID, tmp->mapSymbol, tmp->group, tmp->isPassable)
{
}