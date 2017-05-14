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
#include "Door.h"
#include "Menu.h"

#define ChoiceVect std::vector< std::pair<std::string, int> >

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
	
	void loadLevel();
	
	LevelState getLevelState();

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
	
	MyObject* getFloor( std::vector<MyObject*> vect_floors, int index );
		
	void ingameUpdate();
};

#endif /* LEVEL_H */

