#include "Levels.h"

Levels::Levels(Screen* screen) : player(Handler::getPlayer()), gameScreen(player),
		screen(screen), currTurn(PLAYER), currState(INIT), msgBuffer(screen->infoScreenHeight - 2),
		msgCount(0)
{
	srand(time(NULL));
	
	// Init game menu
	ChoiceVect vect_GameMenu;
	vect_GameMenu.push_back( std::make_pair("Resume game", INGAME) );
	vect_GameMenu.push_back( std::make_pair("Exit game", EXIT) );
	this->gameMenu.setChoices(vect_GameMenu);
	
	paintMsgs();
	
}

Levels::~Levels() {
	clearLevel();
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
	std::stringstream ss;
		
	switch(currTurn) {
		case(PLAYER):
			tmp = UserInput::getPressedKey();
			if( player->move(vect_levelMap, tmp) ) {
				currTurn = ENEMY;
				ss << "Player moved to: " << player->getY() << "/ " << player->getX();
				addMsg(ss.str());
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
			
			break;
		case(INGAME):
			screen->setCurrScreen(screen->GAME);
			gameScreen.paint(vect_levelMap, screen);
			screen->sRefresh();
			screen->setCurrScreen(screen->INFO);
			paintPlayerInfo();
			paintMsgs();
			screen->sRefresh();
			break;
		case(INGAME_MENU):
			screen->setCurrScreen(screen->STANDARD);
			gameMenu.paint(screen);
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

void Levels::addMsg(std::string msg) {
	// Number of msgs info screen can show: infoScreenHeight - playerInfoRow
	int pos = msgCount % (screen->infoScreenHeight - 2);
	std::cerr << msgCount << "% " << screen->infoScreenHeight - 2 << " = " << pos << std::endl;
	msgBuffer.at(pos) = msg;
	msgCount++;
}

void Levels::paintMsgs() {
	std::cerr << "OUTUPUT:" << std::endl;
	int y = screen->infoScreenHeight - 1;
	for(auto it = msgBuffer.rbegin(); it != msgBuffer.rend(); it++, y--) {
		mvwprintw(screen->getCurrScreen(), y, 0, (*it).c_str());
	}
}

void Levels::paintPlayerInfo() {
	std::stringstream ss;
	Info::Attributes a = player->getAttributes();
	ss << "Player HP: " << a.health << ", SPEED: " << a.speed;
	mvwprintw(screen->getCurrScreen(), 0, 0, ss.str().c_str());
}
