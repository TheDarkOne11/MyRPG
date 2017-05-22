#include "Handler.h"

std::map<MyObject::ObjectGroup, std::vector<MyObject*>> Handler::map_MyObjectsTypes;
std::map<Item::ItemType, std::vector<Item*>> Handler::map_ItemTypes;
Player* Handler::player;

void Handler::clear() {
	// Delete MyObject templates
	for(auto it = map_MyObjectsTypes.begin(); it != map_MyObjectsTypes.end(); it++) {
		for(MyObject* curr : it->second) {
			delete curr;
		}
	}
	delete player;
	
	// Delete Item templates
	for(auto it = map_ItemTypes.begin(); it != map_ItemTypes.end(); it++) {
		for(Item* curr : it->second) {
			delete curr;
		}
	}
}

void Handler::init() {
	srand(time(NULL));
	
	// Initialize Consumable items
	Item* healtPotion = new Item(Info::ID_healthPotion, "Health potion", Item::CONSUMABLE, Info::Attributes(15));
	addItem(healtPotion);
	
	// Initialize Usable items
	Item* fastBoots =  new Item(Info::ID_fastBoots, "Fast boots", Item::USEABLE, Info::Attributes(5, 3));
	addItem(fastBoots);
	Item* gun =  new Item(Info::ID_gun, "Gun", Item::USEABLE, Info::Attributes(2, -1, 0, 3, 0));
	addItem(gun);
	
	// Initialize static objects
	MyObject* door = new StaticObject(Info::ID_Door, '0', true, "Door");
	addObject(door);
	MyObject* wall = new StaticObject(Info::ID_Wall, '#', false, "Wall");
	addObject(wall);
	MyObject* floor = new StaticObject(Info::ID_Floor, '.', true, "Floor");
	addObject(floor);
	
	// Initialize entities
	player = new Player(Info::ID_Player, 'P', "Player", Info::Attributes(50, 2, 5, 3, 5));
	MyObject* mob = new Enemy(Info::ID_Mob, 'M', "Mob", Info::Attributes(10, 1, 2, 2, 10));
	addObject(mob);
	MyObject* mob2 = new Enemy(Info::ID_Mob2, 'N', "Mob2", Info::Attributes(5, 3, 1, 1, 2));
	addObject(mob2);
}

Item* Handler::getItem(const int ID, const Item::ItemType type) {
	auto it = map_ItemTypes.find(type);
	
	if(it == map_ItemTypes.end()) {
		throw "Item type doesn't exist.";
	} else {
		for(Item* curr : it->second) {
			if(curr->getID() == ID) {
				return curr->clone();
			}
		}
	}
	
	throw "No match for group, id found: " + ID;
	return NULL;
}

Item* Handler::getItem(const Item::ItemType type) {
	Item* tmp;
	auto it = map_ItemTypes.find(type);
	
	if(it == map_ItemTypes.end()) {
		throw "Item type doesn't exist.";
	} else {
		int ranID = rand() % it->second.size();
		tmp = it->second[ranID]->clone();
	}
	
	return tmp;
}


void Handler::addItem(Item* item) {
	auto it = map_ItemTypes.find(item->getType());
	
	// Insert new type if it doesn't exist
	if(it == map_ItemTypes.end()) {
		std::vector<Item*> tmp;
		it = map_ItemTypes.insert( make_pair(item->getType(), tmp) ).first;
	}
	
	// Add Item in the vector
	it->second.push_back(item);
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