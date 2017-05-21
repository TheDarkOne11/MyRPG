#include "Item.h"

Item::Item(int ID, std::string name, ItemType type, Info::Attributes attr)
		: ID(ID), name(name), type(type), attributes(attr), equiped(false)
{
}

Item::Item(const Item* temp) : ID(temp->ID), name(temp->name), 
		type(temp->type), attributes(temp->attributes), equiped(temp->equiped)
{
}

Item::~Item() 
{
}


Item* Item::clone() const {
	return new Item(this);
}

int Item::getID() const {
	return ID;
}

Info::Attributes Item::getAttributes() const {
	return attributes;
}

bool Item::getEquiped() const {
	return equiped;
}

void Item::setEquiped(bool equiped) {
	this->equiped = equiped;
}

std::string Item::getName() const {
	return name;
}

Item::ItemType Item::getType() const {
	return type;
}

std::string Item::getInfo() const {
	// TODO
	return "";
}
