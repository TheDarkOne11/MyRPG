#include "MyObject.h"

MyObject::MyObject(int ID, char mapSymbol, ObjectGroup type)	
							: ID(ID), mapSymbol(mapSymbol) , group(type)
{

}

MyObject::~MyObject() 
{
}

void MyObject::paint() {
	mvprintw(y, x, "%c", mapSymbol);
}

void MyObject::addObject(int y, int x) {
	this->x = x;
	this->y = y;
}

int MyObject::getX() {
	return x;
}
	
int MyObject::getY() {
	return y;
}

MyObject::ObjectGroup MyObject::getGroup() {
	return group;
}