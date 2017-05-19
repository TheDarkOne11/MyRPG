#ifndef CAMERA_H
#define CAMERA_H

#include <vector>
#include <sstream>
#include "Handler.h"
#include "Player.h"
#include "Info.h"
#include "Screen.h"
#include "MsgBox.h"

/**
 * TODO Documentation
 */
class GameScreen {
public:
	GameScreen(Player*& player);
		
	/**
	 * Paints only those MyObjects that are in the game screen.
	 * MyObject is in the game screen when its coordinates are between top-right and bottom-left corners of the game screen.
	 * @param levelMap 2D vector of all MyObjects currently placed in the current level
	 */
	void paint(const LevelMap & levelMap, Screen* screen, MsgBox* msgBox);
	
	void paintInfoBox(Screen* screen, MsgBox* msgBox);
	
private:
	const Player* player;
	
	int offsetY, offsetX;
};

#endif /* CAMERA_H */

