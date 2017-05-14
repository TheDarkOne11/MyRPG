#include "Info.h"

int Info::width = 0;
int Info::height = 0;
std::map<MyObject::ObjectGroup, std::vector<MyObject*>> Info::map_MyObjectsTypes;
Player* Info::player;

Info::Info() {
	srand(time(NULL));
	init();
}

Info::~Info() {
	for(auto it = map_MyObjectsTypes.begin(); it != map_MyObjectsTypes.end(); it++) {
		for(MyObject* curr : it->second) {
			delete curr;
		}
	}
}

void Info::update() {
	getmaxyx(stdscr, height, width);
}

void Info::init() {
	// Initialize static objects
	MyObject* door = new Door(ID_Door, '0', true);
	addObject(door);
	MyObject* wall = new Wall(ID_Wall, '#', false);
	addObject(wall);
	MyObject* floor = new Floor(ID_Floor, '.', true);
	addObject(floor);
	
	// Initialize entities
	player = new Player(ID_Player, 'P', 50, 1, 5, 2, 3);
	MyObject* mob = new Mob(ID_Mob, 'M', 10, 1, 2, 1, 1);
	addObject(mob);
	MyObject* mob2 = new Mob(ID_Mob2, 'N', 10, 1, 2, 1, 1);
	addObject(mob2);
}

void Info::addObject(MyObject* object) {
	auto it = map_MyObjectsTypes.find(object->getGroup());
	
	// Insert new group if it doesn't exist
	if(it == map_MyObjectsTypes.end()) {
		std::vector<MyObject*> tmp;
		it = map_MyObjectsTypes.insert( make_pair(object->getGroup(), tmp) ).first;
	}
	
	// Add MyObject in the vector
	it->second.push_back(object);
}

DefiningPair Info::getMyObjectID(const char mapSymbol) {
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

MyObject* Info::getMyObject(const char mapSymbol) {
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

MyObject* Info::getMyObject(const MyObject::ObjectGroup group, const int ID) {
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

MyObject* Info::getMyObject(const MyObject::ObjectGroup group) {
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

Player* Info::getPlayer() {
	return dynamic_cast<Player*> (player->clone());
}

int Info::getHeight() {
	return height;
}

int Info::getWidth() {
	return width;
}