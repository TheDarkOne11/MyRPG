#ifndef SCREEN_H
#define SCREEN_H

#include <ncurses.h>
#include <vector>

class Screen {
public:
	const int infoScreenHeight = 5;
	
	enum ScreenTypes {
		STANDARD = 0,
		GAME = 1,
		INFO = 2
	};
	
	Screen();
	~Screen();
	
	void update();
	
	void sClear();
	
	void sRefresh();
	
	void setCurrScreen(ScreenTypes type);
	
	WINDOW* getCurrScreen();
	
	std::pair<int, int> getCurrDimensions();
	
private:
	int maxHeight, maxWidth;
	
	/**
	 * All types of screen
	 */
	std::vector<WINDOW*> vect_screens;
	
	/**
	 * Screen used currently
	 */
	WINDOW* currScreen;
	
	void addScreen(WINDOW* screen);
};

#endif /* SCREEN_H */

