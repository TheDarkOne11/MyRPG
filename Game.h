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

/**
 * Main class which handles everything.
 */
class Game {
private:
	enum GameState {
		MAIN_MENU,
		GAME,
		EXIT
	};

	GameState currState;
	Screen scr;
	
	
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
};

#endif /* GAME_H */

