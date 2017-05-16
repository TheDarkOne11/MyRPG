#include "Floor.h"

Floor::Floor(int ID, char mapSymbol, bool isPassable) : StaticObject(ID, mapSymbol, isPassable)
{
}

Floor::Floor(const Floor* temp) : StaticObject(temp) 
{
}

MyObject* Floor::clone() const {
	return new Floor(this);
}