#ifndef LEVEL_H
#define LEVEL_H

#include <vector>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include "MyObject.h"
#include "Entity.h"
#include "StaticObject.h"
#include "Player.h"
#include "Handler.h"
#include "GameScreen.h"
#include "Enemy.h"
#include "Door.h"
#include "Menu.h"
#include "Info.h"
#include "FileHandler.h"

class Levels {
public:
	enum Turns {
		PLAYER,
		ENEMY
	};
	
	enum LevelState {
		INIT,		// Went from Main menu to game
		INGAME,
		INGAME_MENU,
		INVENTORY,
		NEXT_LEVEL,
		EXIT
	};
	
	Levels();
	~Levels();
	
	void clearLevel();
	
	void update();
	void paint();
		
	LevelState getLevelState();

private:
	/**
	 * All MyObjects that were placed in the current level are stored here.
	 */
	LevelMap vect_levelMap;
	/**
	 * Stores all enemy Entities that were added to current level.
	 */
	std::vector<Enemy*> vect_enemiesInLevel;
	Player* player;
	GameScreen* gameScreen;
	FileHandler fileHandler;
	Menu gameMenu;
	
	Turns currTurn;
	LevelState currState;	
			
	void ingameUpdate();
};

#endif /* LEVEL_H */

