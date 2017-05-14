#include "Levels.h"

Levels::Levels() : currTurn(PLAYER), currState(INIT) {
	srand(time(NULL));
	// Get player from ConfigClass
	player = Info::getPlayer();
	
	gameScreen = new GameScreen(player);
}

Levels::~Levels() {
	delete gameScreen;
	vect_enemiesInLevel.clear();
	//TODO Mustn't delete player when going to new level
	
	for(unsigned int y = 0; y < vect_levelMap.size(); y++) {
		for(unsigned int x = 0; x < vect_levelMap[y].size(); x++) {
			MyObject* curr = vect_levelMap[y][x];
			
			// Remove everything but player
			if(curr->getGroup() != player->getGroup() || curr->getID() != player->getID()) {
				delete curr;
			}
		}
		vect_levelMap[y].clear();
	}
	vect_levelMap.clear();
	delete player;
}

void Levels::update() {	
	switch(currState) {
		case(INIT):
			loadLevel();
			currState = INGAME;
			break;
		case(INGAME):
			ingameUpdate();
			break;
	}
	
}

void Levels::paint() {
	gameScreen->paint(vect_levelMap);
}

void Levels::loadLevel() {
	// Used for adding other MyObjects (enemies, items), randomly
	std::vector<MyObject*> vect_floors;
	//TODO Read map from file instead of hardcoding it
	int h = 30;
	int w = 50;
	
	// Read map from file
	for(int y = 0; y < h; y++) {
		std::vector<MyObject*> row;
		for(int x = 0; x < w; x++) {
			MyObject* tmp;
			if(y == 0 || y == h -1 || x == 0 || x == w - 1) {
				tmp = Info::getMyObject('#');
			} else {
				// Floor ' '
				tmp = Info::getMyObject(' ');
				vect_floors.push_back(tmp);
			}
			row.push_back(tmp);
			tmp->addToMap(vect_levelMap, y, x);
		}
		vect_levelMap.push_back(row);
	}
	
	// Add other MyObjects
	addRandomObjects(vect_floors);	
}

void Levels::addRandomObjects(std::vector<MyObject*>& vect_floors) {
	int ranPos = rand() % vect_floors.size();
	int ranNum = rand() % Info::maxEnemiesPerLevel + 1;
		
	// Add player to random position
	this->addToMap(vect_floors, ranPos, player);
	
	// Add door to random position
	ranPos = rand() % vect_floors.size();
	
	// Add random number of random enemies	
	//std::cerr << "Num of Enemies added: " << ranNum << std::endl;
	for(int i = 0; i < ranNum || vect_floors.size() == 0; i++) {
		// Get random enemy
		Enemy* enemy = dynamic_cast<Enemy*> (Info::getMyObject(MyObject::ENTITY));
		ranPos = rand() % vect_floors.size();
		
		vect_enemiesInLevel.push_back(enemy);
		this->addToMap(vect_floors, ranPos, enemy);
		//std::cerr << "Enemy: " << enemy->getID() << "/ " << enemy->getMapSymbol() << std::endl;
	}
	
}

void Levels::addToMap(std::vector<MyObject*>& floors, int index, MyObject* newObject) {
	MyObject* curr = floors[index];
	
	// Add new object to old object's coordinates
	newObject->addToMap(vect_levelMap, curr->getY(), curr->getX());
	
	// Remove old floor
	floors.erase(floors.begin() + index);
}

void Levels::ingameUpdate() {
	switch(currTurn) {
		case(PLAYER):
			// If player moved, enemy has turn
			if( player->move(vect_levelMap, UserInput::getPressedKey()) ) {
				currTurn = ENEMY;
			
				// Enemies turn, we don't have to wait for input
				nodelay(stdscr, true);
			}
			
			break;
		case(ENEMY):
			currTurn = PLAYER;
			
			for(Enemy* curr : vect_enemiesInLevel) {
				curr->AI_update(vect_levelMap, player->getY(), player->getX());
			}
			
			// Players turn, we have to wait for input
			nodelay(stdscr, false);
			break;
	}
	
	gameScreen->update();
}
