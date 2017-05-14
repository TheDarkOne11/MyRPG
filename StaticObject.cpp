#include "StaticObject.h"

StaticObject::StaticObject(int ID, char mapSymbol, bool isPassable) 
					: MyObject(ID, mapSymbol, MyObject::STATIC, isPassable)
{
}

StaticObject::StaticObject(const StaticObject* tmp) 
					: MyObject(tmp->ID, tmp->mapSymbol, tmp->group, tmp->isPassable)
{
}