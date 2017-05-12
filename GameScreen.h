/* 
 * File:   Camera.h
 * Author: petr
 *
 * Created on May 12, 2017, 10:06 AM
 */

#ifndef CAMERA_H
#define CAMERA_H

#include <vector>
#include "ConfigClass.h"
#include "Player.h"

/**
 * TODO Documentation
 */
class GameScreen {
public:
	GameScreen(Player*& player);
	
	void update();
	
	/**
	 * Paints only those MyObjects that are in the game screen.
	 * MyObject is in the game screen when its coordinates are between top-right and bottom-left corners of the game screen.
	 * @param vect_gameMap Map of the game
	 */
	void paint(const std::vector< std::vector<MyObject*> > & vect_gameMap);
	
	/**
	 * Checks if MyObject of these coordinates is in the game screen.
	 * @param y Y-coordinate
	 * @param x X-coordinate
	 * @return true if coordinates are between top-right and bottom-left corners of the game screen.
	 */
	bool isInScreen(const int y, const int x) const;
private:
	Player* player;
	
	int offsetY, offsetX;
};

#endif /* CAMERA_H */

