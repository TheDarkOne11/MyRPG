#include "Levels.h"

Levels::Levels(Screen* screen) : player(Handler::getPlayer()), screen(screen),
		gameScreen(player), attrMenu(player), currTurn(PLAYER), currState(INIT)
{
	srand(time(NULL));
	msgBox = new MsgBox(screen->infoScreenHeight - 2);
	
	// Init game menu
	ChoiceVect vect_GameMenu;
	vect_GameMenu.push_back( std::make_pair("Resume game", INGAME) );
	vect_GameMenu.push_back( std::make_pair("Change attributes", ATTRIBUTES) );
	vect_GameMenu.push_back( std::make_pair("Exit game", EXIT) );
	this->gameMenu.setChoices(vect_GameMenu);
	
	// Load first level
	fileHandler.loadLevel(levelMap, enemiesInLevel, player);
	
	// Ask player for a new player name
	char name[100];
	screen->setCurrScreen(screen->INFO);
	echo();
	nodelay(screen->getCurrScreen(), false);
	mvwprintw(screen->getCurrScreen(), 0, 0, "Write your player name: ");
	screen->sRefresh();
	
	wgetstr(screen->getCurrScreen(), name);
	player->setName(std::string(name));
	noecho();
	nodelay(screen->getCurrScreen(), true);
}

Levels::~Levels() {
	clearLevel();
	delete msgBox;
	delete player;
}

void Levels::clearLevel() {
	enemiesInLevel.clear();
	
	for(unsigned int y = 0; y < levelMap.size(); y++) {
		for(unsigned int x = 0; x < levelMap[y].size(); x++) {
			MyObject* curr = levelMap[y][x];
			
			// Remove everything but player
			if(curr->getID() != Info::ID_Player || curr->getGroup() != MyObject::ENTITY) {
				delete curr;
			}
		}
		levelMap[y].clear();
	}
	levelMap.clear();
}

void Levels::update() {	
	int tmp;
	
	switch(currState) {
		case(INIT):
			// Edit attributes
			if(!attrMenu.update()) {
				currState = INGAME;
			}
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
				currState = (LevelState) tmp;
			}
			break;
		case(INVENTORY):
			
			break;
		case(ATTRIBUTES):
			if(!attrMenu.update()) {
				currState = INGAME_MENU;
			}
			break;
		case(NEXT_LEVEL):
			clearLevel();
			player->prepareToNextLevel();
			fileHandler.loadLevel(levelMap, enemiesInLevel, player);
			currState = INGAME;
			break;
		case(EXIT):
			break;
	}	
}

void Levels::ingameUpdate() {
	std::stringstream ss;
		
	switch(currTurn) {
		case(PLAYER):
			player->update(levelMap, msgBox);
			if( !player->hasActionsLeft() ) {
				// Player has no actions left, enemies turn
				currTurn = ENEMY;
			}
			
			// Check other pressed keys
			switch(UserInput::getPressedKey()) {
				case(UserInput::K_MENU):
					currState = INGAME_MENU;
					break;
			}
			
			// Check if enemies didn't die
			for(auto it = enemiesInLevel.begin(); it != enemiesInLevel.end(); ) {
				Enemy* enemy = *it;
				
				// If enemy is dead, delete him
				if(!enemy->alive()) {
					it = enemiesInLevel.erase(it);
					enemy->die(levelMap);
					delete enemy;
				} else {
					it++;
				}
			}
			
			break;
		case(ENEMY):
			for(Enemy* curr : enemiesInLevel) {
				curr->AI_update(levelMap, player, msgBox);
			}
			
			currTurn = PLAYER;
			break;
	}
		
	// Player found door, next level
	if(player->getDoorFound()) {
		currState = NEXT_LEVEL;
	}
}

void Levels::paint() {
	switch(currState) {
		case(INIT):
			attrMenu.paint(screen);
			break;
		case(INGAME):
			screen->setCurrScreen(screen->GAME);
			gameScreen.paint(levelMap, screen, msgBox);
			break;
		case(INGAME_MENU):
			screen->setCurrScreen(screen->STANDARD);
			gameMenu.paint(screen);
			break;
		case(INVENTORY):
			
			break;
		case(ATTRIBUTES):
			attrMenu.paint(screen);
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