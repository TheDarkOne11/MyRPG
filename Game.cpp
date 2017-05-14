#include "Game.h"

Game::Game() : currState(MAIN_MENU) {
	// Init Ncurses
	initscr();
	keypad(stdscr,true);
	curs_set(0);				// Hide cursor
	noecho();					// Do not print out pressed keys
	nodelay(stdscr, true);		// Do not wait for input when getch()
	
	// TODO Load Main Menu
	ChoiceList choices;
	choices.push_back( std::make_pair("New Game", GAME) );
	choices.push_back( std::make_pair("Exit", EXIT) );
	mainMenu.setChoices(choices);
	mainMenu.setHead("MAIN MENU");
	
	levels = new Levels();
	//nodelay(stdscr, false);		// Wait for input when getch()
}

Game::~Game() {
	delete levels;
	endwin();
}

void Game::update() {
	int tmp;
	UserInput::update();
	configs.update();
	
	switch(currState) {
		case(MAIN_MENU):
			tmp = mainMenu.update();
			if(tmp != -1) {
				// New state was chosen
				currState = (GameState) tmp;
				nodelay(stdscr, true);
			} else {
				nodelay(stdscr, false);
			}
			
			break;
		case(GAME):
			levels->update();
			break;
			
		case(EXIT):
			break;
	}
	
	// TODO remove
	switch(UserInput::getPressedKey()) {
		case('o'):
			currState = EXIT;
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
		case(EXIT):
			break;
	}
	
	refresh();
}

bool Game::isRunning() const {
	return currState != GameState::EXIT;
}