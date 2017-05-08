#include "Game.h"

Game::Game() {
	currState = GameState::MAIN_MENU;
	
	// Init Ncurses
	initscr();
	keypad(stdscr,true);
	curs_set(0);	// Hide cursor
	noecho();		// Do not print out pressed keys
	nodelay(stdscr, true);		// Do not wait for input when getch()
	getmaxyx(stdscr, maxY, maxX);
}

Game::~Game() {
	endwin();
}

void Game::update() {
	getmaxyx(stdscr, maxY, maxX);
}

void Game::paint() {
	clear();
	mvprintw(maxY/2, maxX/2, "SCREEN INITIATED %d/ %d", maxX/2, maxY/2);
	refresh();
}

bool Game::isRunning() const {
	return currState != GameState::EXIT;
}