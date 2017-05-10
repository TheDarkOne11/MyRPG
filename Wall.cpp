#include "Wall.h"

Wall::Wall(char mapSymbol) : Static_Object(mapSymbol) {
}

MyObject* Wall::clone() const {
	return new Wall(mapSymbol);
}