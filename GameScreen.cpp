#include "GameScreen.h"

GameScreen::GameScreen(Player*& player) : player(player) {
}

void GameScreen::paint(const LevelMap& levelMap, Screen* screen, MsgBox* msgBox) {
	std::pair<int, int> dim = screen->getCurrDimensions();
	
	offsetY = player->getY() - dim.first/2;
	offsetX = player->getX() - dim.second/2;
	
	// Y coordinate of top-left corner
	int startY = player->getY() - dim.first/2;
	// Y coordinate of bottom-right corner
	int endY = player->getY() + dim.first/2;
	
	// Check if not out of bounds
	if(startY < 0) {
		startY = 0;
	}
	
	if(endY > (signed) levelMap.size()) {
		endY = levelMap.size();
	}
	
	// Paint all MyObjects that are in screen
	for(int y = startY; y < (signed) levelMap.size(); y++) {
		int startX = player->getX() - dim.second/2;
		int endX = player->getX() + dim.second/2;
		
		if(startX < 0) {
			startX = 0;
		}

		if(endX > (signed) levelMap[y].size()) {
			endX = levelMap[y].size();
		}
		
		for(int x = startX; x < (signed) levelMap[y].size(); x++) {
			MyObject* curr = levelMap[y][x];
			curr->paint(screen, curr->getY() - offsetY, curr->getX() - offsetX);
		}
	}
	
	screen->sRefresh();
	screen->setCurrScreen(screen->INFO);
	paintInfoBox(screen, msgBox);
	screen->sRefresh();
	
}

void GameScreen::paintInfoBox(Screen* screen, MsgBox* msgBox) {
	std::stringstream ss;
	auto msgBuffer = msgBox->getMsgBuffer();
	Info::Attributes a = player->attributes;
	ss << player->getName() << ": " << player->attributes;
	mvwprintw(screen->getCurrScreen(), 0, 0, ss.str().c_str());
		
	int y = screen->infoScreenHeight - 1;
	for(auto it = msgBuffer.rbegin(); it != msgBuffer.rend(); it++, y--) {
		mvwprintw(screen->getCurrScreen(), y, 0, (*it).c_str());
	}
}
