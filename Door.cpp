#include "Door.h"

Door::Door(int ID, char mapSymbol, bool isPassable, std::string name) 
			: StaticObject(ID, mapSymbol, isPassable, name)
{
}

Door::Door(const StaticObject* temp) : StaticObject(temp) 
{
}

MyObject* Door::clone() const {
	return new Door(this);
}
