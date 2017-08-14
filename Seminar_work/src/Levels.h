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
#include "LoadMenu.h"

/**
 * Class handles creation, update and painting of all levels Player visits.
 */
class Levels {
public:
	enum Turns {
		PLAYER,		///< It's Player's turn to play
		ENEMY		///< It's Enemie's turn to play
	};
	
	enum LevelState {
		INIT,		///< Game initiation.
		INGAME,		///< Player is playing the game.
		INGAME_MENU,///< Player is in ingame menu.
		ATTRIBUTES,	///< Player is in attributes screen.
		INVENTORY,	///< Player is in inventory screen.
		SAVE,		///< Player saves the game.
		LOAD,		///< Player loads new game from saved file.
		NEXT_LEVEL,	///< Player moves to the next level.
		PLAYER_DEAD,///< Death screen
		EXIT		///< Player exited the game.
	};
	
	/**
	 * If fileName is not specified, loads new level. 
	 * Otherwise loads level from the file with specified fileName.
	 * @param screen
	 * @param fileName is the name of the file we want to load level from.
	 */
	Levels(Screen* screen, std::string fileName = "");
	~Levels();
	
	/**
	 * Deletes all objects in the level map but Player.
	 */
	void clearLevel();
	
	void update();
	void paint();
		
	/**
	 * @return Current state of the game.
	 */
	LevelState getLevelState() const;

private:
	LevelMap levelMap;	///< All MyObjects that were placed in the current level are stored here.
	std::vector<Enemy*> enemiesInLevel;		///< Stores all enemy Entities that were added to current level.
	Player* player;
	Screen* screen;
	GameScreen gameScreen;
	AttributesMenu attrMenu;
	InventoryMenu invMenu;
	LoadMenu loadMenu;
	MsgBox* msgBox;
	FileHandler fileHandler;
	Menu gameMenu;
	
	Turns currTurn;
	LevelState currState;	
	
	/**
	 * Handle ingame updates.
	 * Used to make code easier to read;
	 */
	void ingameUpdate();
	
	/**
	 * Handle load screen update;
	 * Used to make code easier to read;
	 */
	void loadUpdate();
	
	/**
	 * Paint simple dead screen.
	 */
	void paintDeathScreen();
};

#endif /* LEVEL_H */

