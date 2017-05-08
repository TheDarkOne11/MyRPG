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
#include "Screen.h"

/**
 * Class represents the whole game.
 * It handles all updates and paints.
 */
class Game {
public:
	/**
	 * All different major game states.
	 */
	enum GameState {
		MAIN_MENU,
		GAME,
		EXIT
	};
	
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
	
private:
	GameState currState;
	Screen scr;
};

#endif /* GAME_H */

