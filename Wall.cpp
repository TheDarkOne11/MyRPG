#include "Wall.h"

Wall::Wall(char mapSymbol) : StaticObject(mapSymbol) {
}

Wall::Wall(const Wall* temp) : StaticObject(temp) {
}

MyObject* Wall::clone() const {
	return new Wall(this);
}