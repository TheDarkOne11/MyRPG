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
#include "ConfigClass.h"
#include "UserInput.h"
#include "GameScreen.h"

class Levels {
public:
	
	Levels();
	~Levels();
	
	void update();
	void paint();
	
	void fillMap();

private:
	/**
	 * All MyObjects that were placed in the current level are stored here.
	 */
	std::vector< std::vector<MyObject*> > vect_gameMap;
	/**
	 * Stores all enemy Entities that were added to current level.
	 */
	std::vector<Entity*> vect_enemiesInLevel;
	Player* player;
	GameScreen* gameScreen;
		
	/**
	 * Addes other MyObjects (enemies, items) to the map randomly.
	 * @param floors All positions in the game map where we can add new MyObjects
	 */
	void addRandomObjects(std::vector<MyObject*>& floors);
	

	void addToMap(std::vector<MyObject*>& floors, int index, MyObject* newObject);
};

#endif /* LEVEL_H */

