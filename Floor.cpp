#include "Floor.h"

Floor::Floor(int ID, char mapSymbol, bool isPassable, std::string name) 
			: StaticObject(ID, mapSymbol, isPassable, name)
{
}

Floor::Floor(const Floor* temp) : StaticObject(temp) 
{
}

MyObject* Floor::clone() const {
	return new Floor(this);
}