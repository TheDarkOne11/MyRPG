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
	
	Level* level;
	GameState currState;
	int maxX, maxY;

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
	bool isRunning();
};

#endif /* GAME_H */

