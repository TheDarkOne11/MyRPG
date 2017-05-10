#include "ConfigClass.h"

Player* ConfigClass::player;

ConfigClass::ConfigClass() {
	init();
}

ConfigClass::~ConfigClass() {
	
}

void ConfigClass::init() {
	std::cerr << "Initialization started" << std::endl;
	
	// Initialize static objects
	MyObject* wall = new Wall();
	addObject(wall);
	
	// Initialize entities
	player = new Player('P', 50, 5, 1, 2);
}

void ConfigClass::addObject(MyObject* object) {
	auto it = mapMyObjectsTypes.find(object->getGroup());
	
	// Insert new group if it doesn't exist
	if(it == mapMyObjectsTypes.end()) {
		std::vector<MyObject*> tmp;
		it = mapMyObjectsTypes.insert( make_pair(object->getGroup(), tmp) ).first;
	}
	
	// Add MyObject in the vector
	it->second.push_back(object);
}

Player* ConfigClass::getPlayer() {
	return player;	// TODO cloning
}