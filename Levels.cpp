#include "Levels.h"

Levels::Levels(Screen* screen, std::string fileName) : player(NULL), screen(screen), 
		currTurn(PLAYER), currState(INIT)
{
	srand(time(NULL));
	msgBox = new MsgBox(screen->infoScreenHeight - 2);
	
	// Init game menu
	ChoiceVect vect_GameMenu;
	vect_GameMenu.push_back( std::make_pair("Resume game", INGAME) );
	vect_GameMenu.push_back( std::make_pair("Change attributes", ATTRIBUTES) );
	vect_GameMenu.push_back( std::make_pair("Inventory", INVENTORY) );
	vect_GameMenu.push_back( std::make_pair("Save", SAVE) );
	vect_GameMenu.push_back( std::make_pair("Load", LOAD) );
	vect_GameMenu.push_back( std::make_pair("Exit game", EXIT) );
	this->gameMenu.setChoices(vect_GameMenu);
	
	if(fileName.compare("") == 0) {
		// Load new level
		player = dynamic_cast <Player*> (Handler::getMyObject(MyObject::ENTITY, Info::ID_Player));
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
	} else {
		// Load level from file
		currState = INGAME;
		fileHandler.loadGame(fileName, levelMap, enemiesInLevel, player);
	}
	
	// Set screens
	gameScreen.setPlayer(player);
	attrMenu.setPlayer(player);
	invMenu.setPlayer(player);
}

Levels::~Levels() {
	clearLevel();
	delete msgBox;
	delete player;
}

void Levels::clearLevel() {
	enemiesInLevel.clear();
	
	// Clear levelMap
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
				currState = PLAYER_DEAD;
			}
			break;
		case(INGAME_MENU):
			tmp = gameMenu.update();
			if(tmp != -1) {
				currState = (LevelState) tmp;
			}
			break;
		case(INVENTORY):
			if(!invMenu.update()) {
				currState = INGAME_MENU;
			}
			break;
		case(ATTRIBUTES):
			if(!attrMenu.update()) {
				currState = INGAME_MENU;
			}
			break;
		case(SAVE):
			fileHandler.saveGame(levelMap, player->getName());
			currState = INGAME_MENU;
			break;
		case(LOAD):
			loadUpdate();
			break;
		case(NEXT_LEVEL):
			clearLevel();
			player->prepareToNextLevel();
			fileHandler.loadLevel(levelMap, enemiesInLevel, player);
			currState = INGAME;
			break;
		case(PLAYER_DEAD):
			if(UserInput::getPressedKey() == UserInput::K_ENTER)
				currState = EXIT;
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
				case(UserInput::K_ESC):
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

void Levels::loadUpdate() {
	std::string fileName;
	switch( loadMenu.update(fileName) ) {
		case(1):
			// FileName chosen
			clearLevel();
			delete player;
			fileHandler.loadGame(fileName, levelMap, enemiesInLevel, player);
			// Set screens
			gameScreen.setPlayer(player);
			attrMenu.setPlayer(player);
			invMenu.setPlayer(player);
			currState = INGAME;
			break;
		case(0):
			// Return
			currState = INGAME_MENU;
			break;
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
			invMenu.paint(screen);
			break;
		case(ATTRIBUTES):
			attrMenu.paint(screen);
			break;
		case(SAVE):
			break;
		case(LOAD):
			loadMenu.paint(screen);
			break;
		case(NEXT_LEVEL):
			break;
		case(PLAYER_DEAD):
			paintDeadScreen();
			break;
		case(EXIT):
			break;
	}
}

Levels::LevelState Levels::getLevelState() {
	return currState;
}

void Levels::paintDeadScreen() {
	std::stringstream ss;
	screen->setCurrScreen(Screen::STANDARD);
	std::pair<int, int> dim = screen->getCurrDimensions();
	ss << "Levels cleared: " << player->getLevelsCleared();
	int y = dim.first/2;
	int x = (dim.second - ss.str().size())/2;
	mvwprintw(screen->getCurrScreen(), y, x, ss.str().c_str());
	ss.str("");
	
	ss << "Enemies killed: " << player->getEnemiesKilled();
	y = dim.first/2 + 2;
	x = (dim.second - ss.str().size())/2;
	mvwprintw(screen->getCurrScreen(), y, x, ss.str().c_str());
	ss.str("");
	
	ss << "Press ENTER to go back to main menu.";
	y = dim.first/2 + 4;
	x = (dim.second - ss.str().size())/2;
	mvwprintw(screen->getCurrScreen(), y, x, ss.str().c_str());
}
