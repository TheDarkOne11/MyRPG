#include "MyObject.h"

MyObject::MyObject(int ID, char mapSymbol, ObjectGroup type, bool isPassable)	
							: ID(ID), x(0), y(0), mapSymbol(mapSymbol), 
							group(type), isPassable(isPassable)
{

}

MyObject::~MyObject() 
{
}

void MyObject::paint(const int y, const int x) {
	mvprintw(y, x, "%c", mapSymbol);
}

void MyObject::update() {
	
}

void MyObject::addToMap(std::vector< std::vector<MyObject*> >& vect_gameMap, int y, int x) {
	this->x = x;
	this->y = y;
	vect_gameMap[y][x] = this;
}

int MyObject::getID() const {
	return ID;
}

int MyObject::getX() const {
	return x;
}
	
int MyObject::getY() const {
	return y;
}

MyObject::ObjectGroup MyObject::getGroup() const {
	return group;
}

bool MyObject::getPassable() const {
	return isPassable;
}

char MyObject::getMapSymbol() const {
	return mapSymbol;
}