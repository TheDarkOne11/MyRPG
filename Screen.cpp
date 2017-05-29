#include "Screen.h"

Screen::Screen() {
	// Init Ncurses
	initscr();
	currScreen = stdscr;
	curs_set(0);				// Hide cursor
	noecho();					// Do not print out pressed keys	
	cbreak();
	ESCDELAY = 250;				// Set delay of ESCAPE key
	getmaxyx(stdscr, maxHeight, maxWidth);

	// Init custom windows
	addScreen( stdscr );
	addScreen( newwin(maxHeight - infoScreenHeight, maxWidth, 0, 0) );
	addScreen( newwin(infoScreenHeight, maxWidth, maxHeight - infoScreenHeight, 0) );
	addScreen( newwin(maxHeight - infoScreenHeight, maxWidth, 0, 0) );
}

Screen::~Screen() {
	// Delete all custom windows.
	for(auto it = vect_screens.begin() + 1; it != vect_screens.end(); it++) {
		delwin(*it);
	}
	
	endwin();
}

void Screen::update() {
	int oldHeight = maxHeight;
	int oldWidth = maxWidth;
	getmaxyx(stdscr, maxHeight, maxWidth);
	
	if(oldHeight != maxHeight || oldWidth != maxWidth) {
		wresize(vect_screens[1], maxHeight - infoScreenHeight, maxWidth);
		wresize(vect_screens[2], infoScreenHeight, maxWidth);
		mvwin(vect_screens[2], maxHeight - infoScreenHeight, 0);
		wresize(vect_screens[3], maxHeight - infoScreenHeight, maxWidth);
	}
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

void Screen::setCurrScreen(ScreenTypes type) {
	currScreen = vect_screens.at(type);
	sClear();
}


WINDOW* Screen::getCurrScreen() const {
	return currScreen;
}

std::pair<int, int> Screen::getCurrDimensions() const {
	std::pair<int, int> p;
	
	getmaxyx(currScreen, p.first, p.second);
	
	return p;
}
