#include "Game.h"

Game::Game() : currState(MAIN_MENU) {
	// Init Ncurses
	initscr();
	keypad(stdscr,true);
	curs_set(0);				// Hide cursor
	noecho();					// Do not print out pressed keys
	nodelay(stdscr, true);		// Do not wait for input when getch()
	
	// TODO Load and pain Main Menu
	ChoiceList choices;
	choices.push_back( std::make_pair("New Game", GAME) );
	choices.push_back( std::make_pair("Exit", EXIT) );
	mainMenu.setChoices(choices);
	
	levels = new Levels();
	//nodelay(stdscr, false);		// Wait for input when getch()
}

Game::~Game() {
	delete levels;
	endwin();
}

void Game::update() {
	int tmp;
	configs.update();
	
	switch(currState) {
		case(MAIN_MENU):
			// Update currState when choice was chosen
			tmp = mainMenu.update();
			if(tmp != -1) {
				currState = (GameState) tmp;
			}
			
			nodelay(stdscr, false);
			break;
		case(GAME):
			levels->update();
			break;
	}
}

void Game::paint() {
	clear();
	
	switch(currState) {
		case(MAIN_MENU):
			mainMenu.paint();
			break;
		case(GAME): 
			levels->paint();
			break;
	}
	
	switch(ConfigClass::getPressedKey()) {
		case('o'):
			currState = EXIT;
			break;
	}
	
	refresh();
}

bool Game::isRunning() const {
	return currState != GameState::EXIT;
}