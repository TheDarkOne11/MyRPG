#include "Levels.h"

Levels::Levels() {
	// Get player from ConfigClass
	player = ConfigClass::getPlayer();
	fillMap();
	gameScreen = new GameScreen(player);
}

Levels::~Levels() {
	delete gameScreen;
	//TODO Mustn't delete player when going to new level
	
	for(unsigned int y = 0; y < vect_gameMap.size(); y++) {
		for(unsigned int x = 0; x < vect_gameMap[y].size(); x++) {
			delete vect_gameMap[y][x];
		}
	}
}

void Levels::update() {
	switch(UserInput::getPressedKey()) {
		case(KEY_UP):
			player->move(player->getY() - 1, player->getX());
			break;
		case(KEY_DOWN):
			player->move(player->getY() + 1, player->getX());
			break;
		case(KEY_LEFT):
			player->move(player->getY(), player->getX() - 1);
			break;
		case(KEY_RIGHT):
			player->move(player->getY(), player->getX() + 1);
			break;
	}
	
	gameScreen->update();
}

void Levels::paint() {
	gameScreen->paint(vect_gameMap);
}

void Levels::fillMap() {
	// Used for adding other MyObjects (enemies, items), randomly
	std::vector<MyObject*> floors;
	//TODO Read map from file instead of hardcoding it
	int h = 30;
	int w = 50;
	
	// Read map from file
	for(int y = 0; y < h; y++) {
		std::vector<MyObject*> row;
		for(int x = 0; x < w; x++) {
			MyObject* tmp;
			if(y == 0 || y == h -1 || x == 0 || x == w - 1) {
				tmp = ConfigClass::getMyObject('#');
			} else {
				// Floor ' '
				tmp = ConfigClass::getMyObject(' ');
				floors.push_back(tmp);
			}
			row.push_back(tmp);
			tmp->addToMap(y, x);
		}
		vect_gameMap.push_back(row);
	}
	
	// Add other MyObjects
	addRandomObjects(floors);
}

void Levels::addRandomObjects(std::vector<MyObject*>& floors) {
	srand(time(NULL));
	int index = rand() % floors.size();
	
	// Add player to random position
	this->addToMap(floors, index, player);
	
}

void Levels::addToMap(std::vector<MyObject*>& floors, int index, MyObject* newObject) {
	MyObject* curr = floors[index];
	
	// Add new object to old object's coordinates
	vect_gameMap[curr->getY()][curr->getX()] = newObject;
	newObject->addToMap(curr->getY(), curr->getX());
	
	// Remove old floor
	floors.erase(floors.begin() + index);
	delete curr;
}