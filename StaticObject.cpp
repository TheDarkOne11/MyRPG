#include "StaticObject.h"

StaticObject::StaticObject(int ID, char mapSymbol, bool isPassable, std::string name) 
					: MyObject(ID, mapSymbol, MyObject::STATIC, isPassable, name)
{
}

StaticObject::StaticObject(const StaticObject* temp) 
					: MyObject(temp->ID, temp->mapSymbol, temp->group, temp->isPassable, temp->name)
{
}

MyObject* StaticObject::clone() const {
	return new StaticObject(this);
}

void StaticObject::paint(Screen* screen, const int y, const int x) {
	if(!inventory.empty()) {
		mvwaddch(screen->getCurrScreen(), y, x, Info::symbol_staticObjectHasItem);
	} else {
		MyObject::paint(screen, y, x);
	}
}
