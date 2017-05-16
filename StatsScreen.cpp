#include "StatsScreen.h"

StatsScreen::~StatsScreen() {
	delwin(window);
}


StatsScreen::StatsScreen(int width, int height) : width(width), height(height), msgBuffer(height)
{
	startY = UserInput::getHeight() - height;
	startX = UserInput::getWidth() - width;
	
	window = newwin(height, width, startY, startX);
}

void StatsScreen::paint() {
	
}

void StatsScreen::addMsg(std::string msg) {
	
}