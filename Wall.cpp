#include "Wall.h"

Wall::Wall(char mapSymbol, bool isPassable) : StaticObject(mapSymbol, isPassable)
{
}

Wall::Wall(const Wall* temp) : StaticObject(temp) {
}

MyObject* Wall::clone() const {
	return new Wall(this);
}