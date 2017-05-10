#include "ConfigClass.h"
#include "Floor.h"

std::map<MyObject::ObjectGroup, std::vector<MyObject*>> ConfigClass::map_MyObjectsTypes;
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
	MyObject* floor = new Floor(' ');
	addObject(floor);
	
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

MyObject* ConfigClass::getMyObject(const char mapSymbol) {
	for(auto it = map_MyObjectsTypes.begin(); it != map_MyObjectsTypes.end(); it++) {
		for(MyObject* curr : it->second) {
			// If match is found, return copy of the MyObject subclass
			if(curr->getMapSymbol() == mapSymbol) {
				return curr->clone();
			}
		}
	}

	throw "No match for mapSymbol found: " + mapSymbol;
	
	return NULL;
}

MyObject* ConfigClass::getMyObject(const MyObject::ObjectGroup, const int ID) {
	//TODO
	
	throw "No match for mapSymbol found: " + ID;
	return NULL;
}

MyObject* ConfigClass::getMyObject(const MyObject::ObjectGroup) {
	
	
	throw "Group doesn't exist.";
	return NULL;
}

MyObject* ConfigClass::getPlayer() {
	return player->clone();	// TODO cloning
}