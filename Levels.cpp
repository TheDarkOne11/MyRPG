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
	delete gameScreen;
	delete player;
}

void Levels::clearLevel() {
	vect_enemiesInLevel.clear();
	
	for(unsigned int y = 0; y < vect_levelMap.size(); y++) {
		for(unsigned int x = 0; x < vect_levelMap[y].size(); x++) {
			MyObject* curr = vect_levelMap[y][x];
			
			// Remove everything but player
			if(curr->getID() != Info::ID_Player || curr->getGroup() != MyObject::ENTITY) {
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
			fileHandler.loadLevel(vect_levelMap, vect_enemiesInLevel, player);
			//loadLevel();
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
			}
			break;
		case(NEXT_LEVEL):
			clearLevel();
			player->prepareToNextLevel();
			fileHandler.loadLevel(vect_levelMap, vect_enemiesInLevel, player);
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
			if( player->move(vect_levelMap, tmp) ) {
				currTurn = ENEMY;
			
				// Enemies turn, we don't have to wait for input
				break;
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
			currTurn = PLAYER;
			break;
	}
	
	gameScreen->update();
	
	// Player found door, next level
	if(player->getDoorFound()) {
		currState = NEXT_LEVEL;
	}
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

Levels::LevelState Levels::getLevelState() {
	return currState;
}
