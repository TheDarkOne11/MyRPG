#include "Floor.h"

Floor::Floor(char mapSymbol) : StaticObject(mapSymbol) {
}

Floor::Floor(const Floor* temp) : StaticObject(temp) 
{
}

MyObject* Floor::clone() const {
	return new Floor(this);
}