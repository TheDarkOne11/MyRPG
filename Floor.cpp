#include "Floor.h"

Floor::Floor(char mapSymbol) : StaticObject(mapSymbol) {
}

MyObject* Floor::clone() const {
	return new Floor(mapSymbol);
}