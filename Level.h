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

class Level {
public:
	
	Level();
	~Level();
	
	void update();
	void paint();
	
	void fillMap(int w, int h);

private:
	std::vector< std::vector<MyObject*> > vect_gameMap;
	Player* player;


};

#endif /* LEVEL_H */

