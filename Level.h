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
#include "MyObject.h"
#include "Entity.h"
#include "StaticObject.h"
#include "Player.h"
#include "ConfigClass.h"
#include "UserInput.h"
#include "GameScreen.h"

class Level {
public:
	
	Level();
	~Level();
	
	void update();
	void paint();
	
	void fillMap();

private:
	/**
	 * All MyObjects that were placed in the current level are stored here.
	 */
	std::vector< std::vector<MyObject*> > vect_gameMap;
	Player* player;
	GameScreen* gameScreen;


};

#endif /* LEVEL_H */

