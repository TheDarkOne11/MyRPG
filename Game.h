#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <list>
#include "Levels.h"
#include "Handler.h"
#include "UserInput.h"
#include "Menu.h"
#include "Info.h"
#include "Screen.h"
#include "LoadMenu.h"

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
		MAIN_MENU,		///< Player in the main menu.
		NEW_LEVELS,		///< Player started new game.
		LOAD_LEVEL,		///< Player loaded a game from a save file.
		LEVELS,			///< Player is in the game.
		LEVELS_ENDED,	///< Player exited the game.
		EXIT			///< Player shut down whole application.
	};
	
	/**
	 * Standard constructor.
	 * Initialize menus, screens etc.
	 */
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
	
private:
	GameState currState;
	Menu mainMenu;
	LoadMenu loadMenu;
	Levels* levels;
	Screen* screen;
	
	/**
	 * Handles update of loading from save file.
	 */
	void loadUpdate();
};

#endif /* GAME_H */

