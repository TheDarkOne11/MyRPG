/* 
 * File:   Level.h
 * Author: petr
 *
 * Created on May 8, 2017, 7:06 PM
 */

#ifndef LEVEL_H
#define LEVEL_H

#include <vector>
#include <ncurses.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include "MyObject.h"
#include "Entity.h"
#include "StaticObject.h"
#include "Player.h"
#include "Info.h"
#include "GameScreen.h"
#include "Enemy.h"
#include "Menu.h"

class Levels {
public:
	enum Turns {
		PLAYER,
		ENEMY
	};
	
	enum LevelState {
		INIT,
		INGAME_MENU,
		INGAME,
		NEXT_LEVEL
	};
	
	Levels();
	~Levels();
	
	void update();
	void paint();
	
	void loadLevel();

private:
	/**
	 * All MyObjects that were placed in the current level are stored here.
	 */
	std::vector< std::vector<MyObject*> > vect_levelMap;
	/**
	 * Stores all enemy Entities that were added to current level.
	 */
	std::vector<Enemy*> vect_enemiesInLevel;
	Player* player;
	GameScreen* gameScreen;
	Menu gameMenu;
	
	Turns currTurn;
	LevelState currState;
		
	/**
	 * Addes other MyObjects (enemies, items) to the map randomly.
	 * @param floors All positions in the game map where we can add new MyObjects
	 */
	void addRandomObjects(std::vector<MyObject*>& floors);
	

	void addToMap(std::vector<MyObject*>& floors, int index, MyObject* newObject);
	
	void ingameUpdate();
};

#endif /* LEVEL_H */

