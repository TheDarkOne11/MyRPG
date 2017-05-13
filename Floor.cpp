#include "Floor.h"

Floor::Floor(char mapSymbol, bool isPassable) : StaticObject(mapSymbol, isPassable)
{
}

Floor::Floor(const Floor* temp) : StaticObject(temp) 
{
}

MyObject* Floor::clone() const {
	return new Floor(this);
}