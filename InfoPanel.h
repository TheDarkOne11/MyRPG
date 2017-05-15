/* 
 * File:   InfoPanel.h
 * Author: petr
 *
 * Created on May 15, 2017, 7:46 PM
 */

#ifndef INFOPANEL_H
#define INFOPANEL_H

#include <ncurses.h>
#include <vector>
#include "Info.h"
#include "UserInput.h"

/**
 * Handles game info panel
 */
class InfoPanel {
public:
	InfoPanel(int width, int height);
	~InfoPanel();
	
	void update();
	
	void paint();
	
	void addMsg(std::string msg);
private:
	int width, height;
	int startY, startX;
	WINDOW* window;
	
	std::vector<std::string> msgBuffer;
};

#endif /* INFOPANEL_H */

