#ifndef SCREEN_H
#define SCREEN_H

#include <ncurses.h>
#include <vector>

class Screen {
public:
	// Height of INFO screen
	const int infoScreenHeight = 5;
	
	enum ScreenTypes {
		STANDARD = 0,
		GAME = 1,
		INFO = 2,
		ATTR_INV = 3
	};
	
	Screen();
	~Screen();
	
	void update();
	
	/**
	 * Clear current window.
	 */
	void sClear();
	
	/**
	 * Refresh current window.
	 */
	void sRefresh();
	
	/**
	 * Selects new current screen using ScreenTypes enum.
	 * @param type is the window we want to select.
	 */
	void setCurrScreen(ScreenTypes type);
	
	/**
	 * @return currently selected window.
	 */
	WINDOW* getCurrScreen() const;
	
	/**
	 * Gets height and width of the currently selected window.
	 * @return pair<height, width> of the currently selected window.
	 */
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
	
	/**
	 * Adds new screen to the vector. 
	 * Adds other configurations to it.
	 * @param screen is the new screen we created.
	 */
	void addScreen(WINDOW* screen);
};

#endif /* SCREEN_H */

