#include "Game.h"

Game::Game() {
	currState = GameState::MAIN_MENU;
	
	// Init Ncurses
	initscr();
	keypad(stdscr,true);
	curs_set(0);				// Hide cursor
	noecho();					// Do not print out pressed keys
	nodelay(stdscr, true);		// Do not wait for input when getch()
	getmaxyx(stdscr, maxY, maxX);
	
	level = new Level();
	level->fillMap(8, 5);
	pressedKey = 0;
}

Game::~Game() {
	endwin();
}

void Game::update() {
	getmaxyx(stdscr, maxY, maxX);
	
	pressedKey = getch();
}

void Game::paint() {
	clear();
	//mvprintw(maxY/2, maxX/2, "SCREEN INITIATED %d/ %d", maxX/2, maxY/2);
	level->paint();
	
	switch(pressedKey) {
		case(KEY_UP):
			
			break;
		case(KEY_DOWN):
			
			break;
		case(KEY_LEFT):
			
			break;
		case(KEY_RIGHT):
			
			break;
		case('o'):
			currState = Game::EXIT;
			break;
	}
	
	refresh();
}

bool Game::isRunning() const {
	return currState != GameState::EXIT;
}