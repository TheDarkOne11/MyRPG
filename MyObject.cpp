#include "MyObject.h"

MyObject::MyObject(int ID, char mapSymbol, ObjectGroup type)	
							: ID(ID), x(0), y(0), mapSymbol(mapSymbol) , group(type)
{

}

MyObject::~MyObject() 
{
}

void MyObject::paint(const int y, const int x) {
	mvprintw(y, x, "%c", mapSymbol);
}

void MyObject::paint() {
	paint(y, x);
}

void MyObject::addToMap(int y, int x) {
	this->x = x;
	this->y = y;
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

char MyObject::getMapSymbol() const {
	return mapSymbol;
}