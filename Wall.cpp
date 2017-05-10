#include "Wall.h"

Wall::Wall(char mapSymbol) : StaticObject(mapSymbol) {
}

MyObject* Wall::clone() const {
	return new Wall(mapSymbol);
}