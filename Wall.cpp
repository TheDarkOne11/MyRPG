#include "Wall.h"

Wall::Wall(int ID, char mapSymbol, bool isPassable) : StaticObject(ID, mapSymbol, isPassable)
{
}

Wall::Wall(const Wall* temp) : StaticObject(temp) {
}

MyObject* Wall::clone() const {
	return new Wall(this);
}