#ifndef SCREEN_H
#define SCREEN_H

#include <ncurses.h>
#include <vector>

/**
 * Class handles initialization and destruction of ncurses screens.
 */
class Screen {
public:
	const int infoScreenHeight = 5;	///< Height of INFO screen
	
	/**
	 * List of all the screens that are available.
	 */
	enum ScreenTypes {
		STANDARD = 0,	///< Standard screen
		GAME = 1,		///< Game screen
		INFO = 2,		///< Info screen
		ATTR_INV = 3	///< Attributes and Inventory screen
	};
	
	Screen();
	~Screen();
	
	/**
	 * Update maximum width and height of the terminal.
	 */
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
	std::pair<int, int> getCurrDimensions() const;
	
private:
	int maxHeight;		///< Current height of the terminal.
	int maxWidth;		///< Current width of the terminal.
	std::vector<WINDOW*> vect_screens;	///< All types of screen
	WINDOW* currScreen;	///< Currently used screen.
	
	/**
	 * Adds new screen to the vector. 
	 * Adds other configurations to it.
	 * @param screen is the new screen we created.
	 */
	void addScreen(WINDOW* screen);
};

#endif /* SCREEN_H */

