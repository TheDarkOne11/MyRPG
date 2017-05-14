/* 
 * File:   Info.h
 * Author: petr
 *
 * Created on May 14, 2017, 6:26 PM
 */

#ifndef INFO_H
#define INFO_H

#include <ncurses.h>

/**
 * Class has important constants.
 * //TODO MOre
 */
class Info {
public:
	// TODO Put them in config file? Maybe update them with player level?
	const static int maxEnemiesPerLevel = 15;
	const static int maxItemsPerLevel = 5;
		
	// List of StaticObject IDs
	const static int ID_Door = 0;
	const static int ID_Floor = 1;
	const static int ID_Wall = 2;
	
	
	// List of Entity IDs
	const static int ID_Player = 0;
	const static int ID_Mob = 1;
	const static int ID_Mob2 = 2;
	
	static void update();
	
	static int getHeight();
	
	static int getWidth();
private:
	// Maximum values of the screen
	static int width, height;
};

#endif /* INFO_H */

