#include "GameScreen.h"

GameScreen::GameScreen(Player*& player) : player(player) {
	update();
}

void GameScreen::update() {
	offsetY = player->getY() - Info::getHeight()/2;
	offsetX = player->getX() - Info::getWidth()/2;
}

bool GameScreen::isInScreen(const int y, const int x) const {
	int screenY = y - offsetY;
	int screenX = x - offsetX;
	
	if(screenY >= 0 && screenX >= 0) {
		if(screenY <= Info::getHeight() && screenX <= Info::getWidth()) {
			return true;
		}
	}
	
	return false;
}

void GameScreen::paint(const std::vector<std::vector<MyObject*> >& vect_levelMap) {
	// Y coordinate of top-left corner
	int startY = player->getY() - Info::getHeight()/2 - offsetY;
	// Y coordinate of bottom-right corner
	int endY = player->getY() + Info::getHeight()/2 - offsetY;
	
	// Check if not out of bounds
	if(startY < 0) {
		startY = 0;
	}
	
	if(endY > (signed) vect_levelMap.size()) {
		endY = vect_levelMap.size();
	}
	
	//FIXME Maybe paint static objects first and then entities
	// Paint all MyObjects that are in screen
	for(int y = startY; y < (signed) vect_levelMap.size(); y++) {
		int startX = player->getX() - Info::getWidth()/2 - offsetX;
		int endX = player->getX() + Info::getWidth()/2 - offsetX;
		
		if(startX < 0) {
			startX = 0;
		}

		if(endX > (signed) vect_levelMap[y].size()) {
			endX = vect_levelMap[y].size();
		}
		
		for(int x = startX; x < (signed) vect_levelMap[y].size(); x++) {
			MyObject* curr = vect_levelMap[y][x];
			curr->paint(curr->getY() - offsetY, curr->getX() - offsetX);
		}
	}
	
	player->paint(player->getY() - offsetY, player->getX() - offsetX);
}