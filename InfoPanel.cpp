#include "InfoPanel.h"

InfoPanel::~InfoPanel() {
	delwin(window);
}


InfoPanel::InfoPanel(int width, int height) : width(width), height(height), msgBuffer(height)
{
	startY = UserInput::getHeight() - height;
	startX = UserInput::getWidth() - width;
	
	window = newwin(height, width, startY, startX);
}

void InfoPanel::paint() {
	
}

void InfoPanel::addMsg(std::string msg) {
	
}