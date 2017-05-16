#include <vector>

#include "Screen.h"

Screen::Screen() {
	// Init Ncurses
	initscr();
	currScreen = stdscr;
	curs_set(0);				// Hide cursor
	noecho();					// Do not print out pressed keys	
	update();

	//TODO full init
	addScreen( stdscr );
	addScreen( newwin(maxHeight - statsScreenHeight, maxWidth, 0, 0) );
	addScreen( newwin(statsScreenHeight, maxWidth, maxHeight - statsScreenHeight, 0) );
}

Screen::~Screen() {
	
	for(auto it = vect_screens.begin() + 1; it != vect_screens.end(); it++) {
		delwin(*it);
	}
	
	endwin();
}

void Screen::update() {
	getmaxyx(stdscr, maxHeight, maxWidth);
}


void Screen::sClear() {
	wclear(currScreen);
}

void Screen::sRefresh() {
	wrefresh(currScreen);
}

void Screen::addScreen(WINDOW* screen) {
	keypad(screen,true);
	nodelay(screen, true);		// Do not wait for input when getch()
	
	vect_screens.push_back(screen);
}

WINDOW* Screen::setCurrScreen(ScreenTypes type) {
	currScreen = vect_screens.at(type);
	sClear();
}


WINDOW* Screen::getCurrScreen() {
	return currScreen;
}

std::pair<int, int> Screen::getCurrDimensions() {
	std::pair<int, int> p;
	
	getmaxyx(currScreen, p.first, p.second);
	
	return p;
}
