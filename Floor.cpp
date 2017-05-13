#include "Floor.h"

Floor::Floor(char mapSymbol, bool isPassable) : StaticObject(mapSymbol, isPassable)
{
}

Floor::Floor(const Floor* temp) : StaticObject(temp) 
{
}

void Floor::addToMap(std::vector<std::vector<MyObject*> >& vect_gameMap, int y, int x) {
	this->y = y;
	this->x = x;
}


MyObject* Floor::clone() const {
	return new Floor(this);
}