#include "Wall.h"

Wall::Wall(char mapSymbol, bool isPassable) : StaticObject(mapSymbol, isPassable)
{
}

Wall::Wall(const Wall* temp) : StaticObject(temp) {
}

void Wall::addToMap(std::vector<std::vector<MyObject*> >& vect_gameMap, int y, int x) {
	this->y = y;
	this->x = x;
}

MyObject* Wall::clone() const {
	return new Wall(this);
}