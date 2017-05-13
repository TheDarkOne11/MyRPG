#include "ConfigClass.h"
#include "Mob.h"

int ConfigClass::width = 0;
int ConfigClass::height = 0;

std::map<MyObject::ObjectGroup, std::vector<MyObject*>> ConfigClass::map_MyObjectsTypes;
Player* ConfigClass::player;

ConfigClass::ConfigClass() {
	srand(time(NULL));
	init();
}

ConfigClass::~ConfigClass() {
	for(auto it = map_MyObjectsTypes.begin(); it != map_MyObjectsTypes.end(); it++) {
		for(MyObject* curr : it->second) {
			delete curr;
		}
	}
}

void ConfigClass::update() {
	getmaxyx(stdscr, height, width);
}

void ConfigClass::init() {
	// Initialize static objects
	MyObject* wall = new Wall('#', false);
	addObject(wall);
	MyObject* floor = new Floor(' ', true);
	addObject(floor);
	
	// Initialize entities
	player = new Player('P', 50, 1, 5, 2, 3);
	MyObject* mob = new Mob('M', 10, 1, 2, 1, 1);
	addObject(mob);
	MyObject* mob2 = new Mob('O', 10, 1, 2, 1, 1);
	addObject(mob2);
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

DefiningPair ConfigClass::getMyObjectID(const char mapSymbol) {
	DefiningPair currPair;
	bool found = false;
	for(auto it = map_MyObjectsTypes.begin(); it != map_MyObjectsTypes.end(); it++) {
		for(MyObject* curr : it->second) {
			// If match is found, return copy of the MyObject subclass
			if(curr->getMapSymbol() == mapSymbol) {
				currPair = std::make_pair(curr->getID(), curr->getGroup());
				found = true;
			}
		}
	}
	
	if(!found) {
		throw "No match for mapSymbol found: " + mapSymbol;
	}
		
	return currPair;
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

MyObject* ConfigClass::getMyObject(const MyObject::ObjectGroup group, const int ID) {
	auto it = map_MyObjectsTypes.find(group);
	
	if(it == map_MyObjectsTypes.end()) {
		throw "Group doesn't exist.";
	} else {
		for(MyObject* curr : it->second) {
			if(curr->getID() == ID) {
				return curr->clone();
			}
		}
	}
	
	throw "No match for group, id found: " + ID;
	return NULL;
}

MyObject* ConfigClass::getMyObject(const MyObject::ObjectGroup group) {
	MyObject* tmp;
	auto it = map_MyObjectsTypes.find(group);
	
	if(it == map_MyObjectsTypes.end()) {
		throw "Group doesn't exist.";
	} else {
		int ranID = rand() % it->second.size();
		tmp = it->second[ranID]->clone();
	}
	
	return tmp;
}

Player* ConfigClass::getPlayer() {
	return dynamic_cast<Player*> (player->clone());
}

int ConfigClass::getHeight() {
	return height;
}

int ConfigClass::getWidth() {
	return width;
}