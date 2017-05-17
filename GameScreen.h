#ifndef CAMERA_H
#define CAMERA_H

#include <vector>
#include "Handler.h"
#include "Player.h"
#include "Info.h"
#include "Screen.h"

/**
 * TODO Documentation
 */
class GameScreen {
public:
	GameScreen(Player*& player);
		
	/**
	 * Paints only those MyObjects that are in the game screen.
	 * MyObject is in the game screen when its coordinates are between top-right and bottom-left corners of the game screen.
	 * @param vect_levelMap 2D vector of all MyObjects currently placed in the current level
	 */
	void paint(const LevelMap & vect_levelMap, Screen* screen);
private:
	const Player* player;
	
	int offsetY, offsetX;
};

#endif /* CAMERA_H */

