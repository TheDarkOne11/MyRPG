#include "MyObject.h"

MyObject::MyObject(int ID, char mapSymbol, ObjectGroup type, 
		bool isPassable, std::string name)	
							: ID(ID), x(0), y(0), mapSymbol(mapSymbol), 
							group(type), isPassable(isPassable), name(name)
{

}

MyObject::~MyObject() 
{
	for(Item* curr : inventory) {
		delete curr;
	}
}

void MyObject::paint(Screen* screen, const int y, const int x) {
	mvwaddch(screen->getCurrScreen(), y, x, mapSymbol);
}

void MyObject::addToMap(LevelMap& levelMap, int y, int x, bool removeFormer) {
	this->x = x;
	this->y = y;
	
	if(removeFormer) {
		delete levelMap[y][x];
	}
	
	levelMap[y][x] = this;
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

std::string MyObject::getName() const {
	return name;
}

InvList& MyObject::getInventory() {
	return inventory;
}
