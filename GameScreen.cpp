#include "GameScreen.h"

GameScreen::GameScreen(Player*& player) : player(player), offsetY(0), offsetX(0) {
}

void GameScreen::update() {
	offsetY = player->getY() - ConfigClass::getHeight()/2;
	offsetX = player->getX() - ConfigClass::getWidth()/2;
}

bool GameScreen::isInScreen(const int y, const int x) const {
	int screenY = y - offsetY;
	int screenX = x - offsetX;
	
	if(screenY >= 0 && screenX >= 0) {
		if(screenY <= ConfigClass::getHeight() && screenX <= ConfigClass::getWidth()) {
			return true;
		}
	}
	
	return false;
}

void GameScreen::paint(const std::vector<std::vector<MyObject*> >& vect_gameMap) {
	// Y coordinate of top-left corner
	int startY = player->getY() - ConfigClass::getHeight()/2 - offsetY;
	// Y coordinate of bottom-right corner
	int endY = player->getY() + ConfigClass::getHeight()/2 - offsetY;
	
	// Check if not out of bounds
	if(startY < 0) {
		startY = 0;
	}
	
	if(endY > vect_gameMap.size()) {
		endY = vect_gameMap.size();
	}
	
	//FIXME Maybe paint static objects first and then entities
	// Paint all MyObjects that are in screen
	for(int y = startY; y < vect_gameMap.size(); y++) {
		int startX = player->getX() - ConfigClass::getWidth()/2 - offsetX;
		int endX = player->getX() + ConfigClass::getWidth()/2 - offsetX;
		
		if(startX < 0) {
			startX = 0;
		}

		if(endX > vect_gameMap[y].size()) {
			endX = vect_gameMap[y].size();
		}
		
		for(int x = startX; x < vect_gameMap[y].size(); x++) {
			MyObject* curr = vect_gameMap[y][x];
			curr->paint(curr->getY() - offsetY, curr->getX() - offsetX);
		}
	}
	
	player->paint(player->getY() - offsetY, player->getX() - offsetX);
}