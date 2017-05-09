/* 
 * File:   Game.h
 * Author: petr
 *
 * Created on May 8, 2017, 4:53 PM
 */

#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <ncurses.h>
#include "Level.h"

/**
 * Class represents the whole game.
 * It handles all updates and paints.
 */
class Game {
private:
	/**
	 * All different major game states.
	 */
	enum GameState {
		MAIN_MENU,
		GAME,
		INGAME_MENU,
		EXIT
	};
	GameState currState;
	// Actual game level
	Level* level;
	
	// Maximum values of the screen
	int maxX, maxY;
	int pressedKey;

public:	
	Game();
	
	~Game();
	
	/**
	 * Updates whole game.
	 */
	void update();
	
	/**
	 * Paints whole game.
	 */
	void paint();
	
	/**
	 * @return true if game is still running.
	 */
	bool isRunning() const;
};

#endif /* GAME_H */

