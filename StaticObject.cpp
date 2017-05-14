#include "StaticObject.h"

StaticObject::StaticObject(int ID, char mapSymbol, bool isPassable) 
					: MyObject(ID, mapSymbol, MyObject::STATIC, isPassable)
{
}

StaticObject::StaticObject(const StaticObject* tmp) 
					: MyObject(tmp->ID, tmp->mapSymbol, tmp->group, tmp->isPassable)
{
}

void StaticObject::addToMap(std::vector<std::vector<MyObject*> >& vect_levelMap, int y, int x) {
	MyObject* curr = vect_levelMap[y][x];
	MyObject::addToMap(vect_levelMap, y, x);
	delete curr;
}