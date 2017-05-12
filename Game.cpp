#include "Game.h"

Game::Game() {
	currState = GameState::MAIN_MENU;
	
	// Init Ncurses
	initscr();
	keypad(stdscr,true);
	curs_set(0);				// Hide cursor
	noecho();					// Do not print out pressed keys
	nodelay(stdscr, true);		// Do not wait for input when getch()
	
	level = new Level();
	level->fillMap();	
}

Game::~Game() {
	delete level;
	endwin();
}

void Game::update() {
	input.update();
	configs.update();
	level->update();
}

void Game::paint() {
	clear();
	//mvprintw(maxY/2, maxX/2, "SCREEN INITIATED %d/ %d", maxX/2, maxY/2);
	level->paint();
	
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