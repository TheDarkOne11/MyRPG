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

void MyObject::addToMap(int y, int x) {
	this->x = x;
	this->y = y;
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