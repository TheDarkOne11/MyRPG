#ifndef CAMERA_H
#define CAMERA_H

#include <vector>
#include "Handler.h"
#include "Player.h"
#include "Info.h"

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
	 * @param vect_levelMap 2D vector of all MyObjects currently placed in the current level
	 */
	void paint(const std::vector< std::vector<MyObject*> > & vect_levelMap);
	
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

