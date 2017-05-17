#include "Wall.h"

Wall::Wall(int ID, char mapSymbol, bool isPassable, std::string name) 
		: StaticObject(ID, mapSymbol, isPassable, name)
{
}

Wall::Wall(const Wall* temp) : StaticObject(temp) {
}

MyObject* Wall::clone() const {
	return new Wall(this);
}