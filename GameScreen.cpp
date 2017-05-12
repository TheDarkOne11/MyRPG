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
	for(unsigned int y = 0; y < vect_gameMap.size(); y++) {
		for(unsigned int x = 0; x < vect_gameMap[y].size(); x++) {
			if( isInScreen(y, x) ) {
				MyObject* curr = vect_gameMap[y][x];
				curr->paint(curr->getY() - offsetY, curr->getX() - offsetX);
			}
		}
	}
	
	player->paint(player->getY() - offsetY, player->getX() - offsetX);
}