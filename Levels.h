#ifndef LEVEL_H
#define LEVEL_H

#include <vector>
#include <list>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <sstream>
#include "MyObject.h"
#include "Entity.h"
#include "StaticObject.h"
#include "Player.h"
#include "Handler.h"
#include "GameScreen.h"
#include "Enemy.h"
#include "Menu.h"
#include "Info.h"
#include "FileHandler.h"
#include "Screen.h"
#include "MsgBox.h"
#include "AttributesMenu.h"
#include "InventoryMenu.h"

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
		ATTRIBUTES,
		INVENTORY,
		NEXT_LEVEL,
		EXIT
	};
	
	Levels(Screen* screen);
	~Levels();
	
	void clearLevel();
	
	void update();
	void paint();
		
	LevelState getLevelState();

private:
	/**
	 * All MyObjects that were placed in the current level are stored here.
	 */
	LevelMap levelMap;
	/**
	 * Stores all enemy Entities that were added to current level.
	 */
	std::vector<Enemy*> enemiesInLevel;
	Player* player;
	Screen* screen;
	GameScreen gameScreen;
	AttributesMenu attrMenu;
	InventoryMenu invMenu;
	MsgBox* msgBox;
	FileHandler fileHandler;
	Menu gameMenu;
	
	Turns currTurn;
	LevelState currState;	
			
	void ingameUpdate();
};

#endif /* LEVEL_H */

