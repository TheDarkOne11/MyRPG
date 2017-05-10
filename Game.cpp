#include "Game.h"

int Game::maxX, Game::maxY;

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
	level->fillMap(maxY - 1, maxX - 1);	
}

Game::~Game() {
	delete level;
	endwin();
}

void Game::update() {
	getmaxyx(stdscr, maxY, maxX);
	input.update();
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