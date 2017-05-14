#include "Door.h"

Door::Door(int ID, char mapSymbol, bool isPassable) : StaticObject(ID, mapSymbol, isPassable)
{
}

Door::Door(const StaticObject* temp) : StaticObject(temp) 
{
}

MyObject* Door::clone() const {
	return new Door(this);
}
