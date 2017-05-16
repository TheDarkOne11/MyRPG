#include "MyObject.h"

MyObject::MyObject(int ID, char mapSymbol, ObjectGroup type, bool isPassable)	
							: ID(ID), x(0), y(0), mapSymbol(mapSymbol), 
							group(type), isPassable(isPassable)
{

}

MyObject::~MyObject() 
{
}

void MyObject::paint(Screen* screen, const int y, const int x) {
	mvwprintw(screen->getCurrScreen(), y, x, "%c", mapSymbol);
}

void MyObject::update() {
	
}

void MyObject::addToMap(LevelMap& vect_levelMap, int y, int x, bool removeFormer) {
	this->x = x;
	this->y = y;
	
	if(removeFormer) {
		delete vect_levelMap[y][x];
	}
	
	vect_levelMap[y][x] = this;
}

int MyObject::getID() const {
	return ID;
}

int MyObject::getX() const {
	return x;
}

void MyObject::setCoordinates(int y, int x) {
	this->y = y;
	this->x = x;
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