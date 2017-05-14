#include "StaticObject.h"

int StaticObject::lastID = 0;

StaticObject::StaticObject(char mapSymbol, bool isPassable) 
					: MyObject(lastID, mapSymbol, MyObject::STATIC, isPassable)
{
	lastID++;
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