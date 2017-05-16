#include "GameScreen.h"

GameScreen::GameScreen(Player*& player) : player(player) {
}

void GameScreen::paint(const LevelMap& vect_levelMap, Screen* screen) {
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
	
	if(endY > (signed) vect_levelMap.size()) {
		endY = vect_levelMap.size();
	}
	
	// Paint all MyObjects that are in screen
	for(int y = startY; y < (signed) vect_levelMap.size(); y++) {
		int startX = player->getX() - dim.second/2;
		int endX = player->getX() + dim.second/2;
		
		if(startX < 0) {
			startX = 0;
		}

		if(endX > (signed) vect_levelMap[y].size()) {
			endX = vect_levelMap[y].size();
		}
		
		for(int x = startX; x < (signed) vect_levelMap[y].size(); x++) {
			MyObject* curr = vect_levelMap[y][x];
			curr->paint(screen, curr->getY() - offsetY, curr->getX() - offsetX);
		}
	}
}