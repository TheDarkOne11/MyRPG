#include "MyObject.h"
#include "Handler.h"

MyObject::MyObject(int ID, char mapSymbol, ObjectGroup group, 
		bool isPassable, std::string name)	
							: ID(ID), x(0), y(0), mapSymbol(mapSymbol), 
							group(group), isPassable(isPassable), name(name)
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

void MyObject::save(std::ofstream& file) {
	// Save important data
	file << ID << " " << group << "\n" << y << " " << x << '\n';
	
	// Save inventory
	for(auto it = inventory.begin(); it != inventory.end(); it++) {
		file << (*it)->getID() << " " << (*it)->getType() << " ";
	}
	file << '\n';
	file.flush();
}

void MyObject::load(std::ifstream& file) {
	std::string line;
	std::getline(file, line);
	y = stoi(Info::parseString(line));
	x = stoi(Info::parseString(line));
	
	// Load inventory
	std::getline(file, line);
	while(line.compare(" ") != 0 && !line.empty()) {
		int ID = stoi(Info::parseString(line));
		Item::ItemType type = (Item::ItemType) stoi(Info::parseString(line));
		
		inventory.push_back( Handler::getItem(type, ID) );
	}
}

