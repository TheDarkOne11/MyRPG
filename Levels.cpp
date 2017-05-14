#include "Levels.h"
#include "Game.h"

Levels::Levels() : currTurn(PLAYER), currState(INIT) {
	srand(time(NULL));
	
	// Get player from ConfigClass
	player = Handler::getPlayer();
	
	// Init game menu
	ChoiceVect vect_GameMenu;
	vect_GameMenu.push_back( std::make_pair("Resume game", INGAME) );
	vect_GameMenu.push_back( std::make_pair("Exit game", EXIT) );
	this->gameMenu.setChoices(vect_GameMenu);
	
	gameScreen = new GameScreen(player);
}

Levels::~Levels() {
	clearLevel();
	delete player;
}

void Levels::clearLevel() {
	delete gameScreen;
	vect_enemiesInLevel.clear();
	
	for(unsigned int y = 0; y < vect_levelMap.size(); y++) {
		for(unsigned int x = 0; x < vect_levelMap[y].size(); x++) {
			MyObject* curr = vect_levelMap[y][x];
			
			// Remove everything but player
			if(curr->getID() != Handler::ID_Player || curr->getGroup() != MyObject::ENTITY) {
				delete curr;
			}
		}
		vect_levelMap[y].clear();
	}
	vect_levelMap.clear();
}

void Levels::update() {	
	int tmp;
	
	switch(currState) {
		case(INIT):
			loadLevel();
			currState = INGAME;
			break;
		case(INGAME):
			ingameUpdate();
			if(!player->alive()) {
				// Player died
				currState = EXIT;
			}
			break;
		case(INGAME_MENU):
			tmp = gameMenu.update();
			if(tmp != -1) {
				// New gamestate chosen
				currState = (LevelState) tmp;
				nodelay(stdscr, true);
			} else {
				nodelay(stdscr, false);
			}
			break;
		case(NEXT_LEVEL):
			clearLevel();
			loadLevel();
			currState = INGAME;
			break;
		case(EXIT):
			break;
	}	
}

void Levels::ingameUpdate() {
	int tmp;
	
	switch(currTurn) {
		case(PLAYER):
			tmp = UserInput::getPressedKey();
			// If player moved, enemy has turn
			if( player->move(vect_levelMap, tmp) ) {
				currTurn = ENEMY;
			
				// Enemies turn, we don't have to wait for input
				nodelay(stdscr, true);
				return;
			}
			
			// Check other pressed keys
			switch(tmp) {
				case(UserInput::K_MENU):
					currState = INGAME_MENU;
					break;
			}
			
			break;
		case(ENEMY):
			for(Enemy* curr : vect_enemiesInLevel) {
				curr->AI_update(vect_levelMap, player->getY(), player->getX());
			}
			
			// Players turn, we have to wait for input
			nodelay(stdscr, false);
			currTurn = PLAYER;
			break;
	}
	
	gameScreen->update();
}

void Levels::paint() {
	switch(currState) {
		case(INIT):
			
			break;
		case(INGAME):
			gameScreen->paint(vect_levelMap);
			break;
		case(INGAME_MENU):
			gameMenu.paint();
			break;
		case(NEXT_LEVEL):
			
			break;
		case(EXIT):
			
			break;
	}
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
				tmp = Handler::getMyObject('#');
			} else {
				// Floor ' '
				tmp = Handler::getMyObject('.');
				vect_floors.push_back(tmp);
			}
			tmp->setCoordinates(y, x);
			row.push_back(tmp);
		}
		vect_levelMap.push_back(row);
	}
	
	// Add other MyObjects
	addRandomObjects(vect_floors);	
}

void Levels::addRandomObjects(std::vector<MyObject*>& vect_floors) {
	MyObject* curr;
	int ranPos = rand() % vect_floors.size();
	int ranNum = rand() % Handler::maxEnemiesPerLevel + 1;
		
	// Add player to random position
	curr = getFloor(vect_floors, ranPos);
	player->addToMap(vect_levelMap, curr->getY(), curr->getX(), true);
	
	// Add door to random position
	MyObject* door = Handler::getMyObject(MyObject::STATIC, Handler::ID_Door);
	ranPos = rand() % vect_floors.size();
	curr = getFloor(vect_floors, ranPos);
	door->addToMap(vect_levelMap, curr->getY(), curr->getX(), true);
	
	// Add random number of random enemies	
	//std::cerr << "Num of Enemies added: " << ranNum << std::endl;
	for(int i = 0; i < ranNum || vect_floors.size() == 0; i++) {
		// Get random enemy
		Enemy* enemy = dynamic_cast<Enemy*> (Handler::getMyObject(MyObject::ENTITY));
		ranPos = rand() % vect_floors.size();
		curr = getFloor(vect_floors, ranPos);
		
		vect_enemiesInLevel.push_back(enemy);
		enemy->addToMap(vect_levelMap, curr->getY(), curr->getX(), true);
		//std::cerr << "Enemy: " << enemy->getID() << "/ " << enemy->getMapSymbol() << std::endl;
	}
	
}

MyObject* Levels::getFloor(std::vector<MyObject*> vect_floors, int index) {
	vect_floors.erase( vect_floors.begin() + index );
	return vect_floors[index];
}

Levels::LevelState Levels::getLevelState() {
	return currState;
}
