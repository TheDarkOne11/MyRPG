#include "MyObject.h"

MyObject::MyObject(int ID, char mapSymbol, ObjectType type)	
							: ID(ID), mapSymbol(mapSymbol) , type(type)
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