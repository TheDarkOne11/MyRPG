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
#include "MyObject.h"
#include "Entity.h"
#include "Static_Object.h"

class Level {
private:
	std::vector< std::vector<MyObject*> > gameMap;

public:
	std::vector< std::vector<std::string> > file;
	
	Level();
	~Level();
	
	void update();
	void paint();
	
	void fillMap(int w, int h);

};

#endif /* LEVEL_H */

