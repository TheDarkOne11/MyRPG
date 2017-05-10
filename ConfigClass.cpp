#include "ConfigClass.h"

Player* ConfigClass::player;

ConfigClass::ConfigClass() {
	init();
}

ConfigClass::~ConfigClass() {
	for(auto it = map_MyObjectsTypes.begin(); it != map_MyObjectsTypes.end(); it++) {
		for(MyObject* curr : it->second) {
			delete curr;
		}
	}
}

void ConfigClass::init() {
	std::cerr << "Initialization started" << std::endl;
	
	// Initialize static objects
	MyObject* wall = new Wall('#');
	addObject(wall);
	
	// Initialize entities
	player = new Player('P', 50, 5, 1, 2);
}

void ConfigClass::addObject(MyObject* object) {
	auto it = map_MyObjectsTypes.find(object->getGroup());
	
	// Insert new group if it doesn't exist
	if(it == map_MyObjectsTypes.end()) {
		std::vector<MyObject*> tmp;
		it = map_MyObjectsTypes.insert( make_pair(object->getGroup(), tmp) ).first;
	}
	
	// Add MyObject in the vector
	it->second.push_back(object);
}

MyObject* ConfigClass::getPlayer() {
	return player->clone();	// TODO cloning
}