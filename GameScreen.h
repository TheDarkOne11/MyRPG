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
 * Handles painting of the game screen.
 * Player is always in the middle of the screen, other MyObjects from the map are painted only
 * if they are in the screen.
 */
class GameScreen {
public:
	/**
	 * Paints only those MyObjects that are in the game screen.
	 * MyObject is in the game screen when its coordinates are between top-right and bottom-left corners of the game screen.
	 * @param levelMap 2D vector of all MyObjects currently placed in the current level
	 * @param screen
	 * @param msgBox
	 */
	void paint(const LevelMap & levelMap, Screen* screen, MsgBox* msgBox);
	
	/**
	 * Paints infobox - game messages, hints etc.
	 * @param screen
	 * @param msgBox
	 */
	void paintInfoBox(Screen* screen, MsgBox* msgBox);
	
	void setPlayer(Player* player);
	
private:
	const Player* player;
	
	int offsetY;	///< Y-offset of the screen. Says how far is the player from actual middle of the screen Y-coordinate. 
	int offsetX;	///< X-offset of the screen. Says how far is the player from actual middle of the screen X-coordinate.
};

#endif /* CAMERA_H */

