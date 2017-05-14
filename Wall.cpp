#include "Wall.h"

Wall::Wall(int ID, char mapSymbol, bool isPassable) : StaticObject(ID, mapSymbol, isPassable)
{
}

Wall::Wall(const Wall* temp) : StaticObject(temp) {
}

void Wall::addToMap(std::vector<std::vector<MyObject*> >& vect_levelMap, int y, int x) {
	this->y = y;
	this->x = x;
}

MyObject* Wall::clone() const {
	return new Wall(this);
}