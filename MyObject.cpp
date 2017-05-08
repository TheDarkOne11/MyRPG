#include "MyObject.h"

MyObject::MyObject(int ID, char mapSymbol) : ID(ID), mapSymbol(mapSymbol) 
{

}

MyObject::~MyObject() 
{
}

void MyObject::addObject(int x, int y) {
	this->x = x;
	this->y = y;
}