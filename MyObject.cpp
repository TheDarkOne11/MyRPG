#include "MyObject.h"

MyObject::MyObject(int ID, char mapSymbol, ObjectType type)	
							: ID(ID), mapSymbol(mapSymbol) , type(type)
{

}

MyObject::~MyObject() 
{
}

void MyObject::addObject(int x, int y) {
	this->x = x;
	this->y = y;
}