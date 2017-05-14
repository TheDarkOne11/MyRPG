#include "Handler.h"

std::map<MyObject::ObjectGroup, std::vector<MyObject*>> Handler::map_MyObjectsTypes;
Player* Handler::player;

void Handler::clear() {
	for(auto it = map_MyObjectsTypes.begin(); it != map_MyObjectsTypes.end(); it++) {
		for(MyObject* curr : it->second) {
			delete curr;
		}
	}
}

void Handler::init() {
	srand(time(NULL));
	
	// Initialize static objects
	MyObject* door = new Door(Info::ID_Door, '0', true);
	addObject(door);
	MyObject* wall = new Wall(Info::ID_Wall, '#', false);
	addObject(wall);
	MyObject* floor = new Floor(Info::ID_Floor, '.', true);
	addObject(floor);
	
	// Initialize entities
	player = new Player(Info::ID_Player, 'P', 50, 1, 5, 2, 3);
	MyObject* mob = new Mob(Info::ID_Mob, 'M', 10, 1, 2, 1, 1);
	addObject(mob);
	MyObject* mob2 = new Mob(Info::ID_Mob2, 'N', 10, 1, 2, 1, 1);
	addObject(mob2);
}

void Handler::addObject(MyObject* object) {
	auto it = map_MyObjectsTypes.find(object->getGroup());
	
	// Insert new group if it doesn't exist
	if(it == map_MyObjectsTypes.end()) {
		std::vector<MyObject*> tmp;
		it = map_MyObjectsTypes.insert( make_pair(object->getGroup(), tmp) ).first;
	}
	
	// Add MyObject in the vector
	it->second.push_back(object);
}

DefiningPair Handler::getMyObjectID(const char mapSymbol) {
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

MyObject* Handler::getMyObject(const char mapSymbol) {
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

MyObject* Handler::getMyObject(const MyObject::ObjectGroup group, const int ID) {
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

MyObject* Handler::getMyObject(const MyObject::ObjectGroup group) {
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

Player* Handler::getPlayer() {
	return dynamic_cast<Player*> (player->clone());
}