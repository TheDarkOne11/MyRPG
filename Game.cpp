#include "Game.h"

Game::Game() {
	currState = GameState::MAIN_MENU;
	
	// Init Ncurses
	initscr();
	keypad(stdscr,true);
	curs_set(0);				// Hide cursor
	noecho();					// Do not print out pressed keys
	nodelay(stdscr, true);		// Do not wait for input when getch()
	
	// TODO Load and pain Main Menu
	levels = new Levels();
	
	nodelay(stdscr, false);		// Wait for input when getch()
}

Game::~Game() {
	delete levels;
	endwin();
}

void Game::update() {
	input.update();
	configs.update();
	levels->update();
}

void Game::paint() {
	clear();
	levels->paint();
	
	switch(UserInput::getPressedKey()) {
		case('o'):
			currState = EXIT;
			break;
	}
	
	refresh();
}

bool Game::isRunning() const {
	return currState != GameState::EXIT;
}