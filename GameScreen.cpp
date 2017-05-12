#include "GameScreen.h"

GameScreen::GameScreen(Player*& player) : player(player), middleY(0), middleX(0), startY(0), startX(0) {
}

void GameScreen::update() {
	middleY = player->getY();
	middleX = player->getX();
	startY = middleY - ConfigClass::getHeight()/2;
	startX = middleX - ConfigClass::getWidth()/2;
}

bool GameScreen::isInScreen(const int y, const int x) const {
	if(y >= startY && x >= startX) {
		if(y <= startY + ConfigClass::getHeight() && x <= ConfigClass::getWidth()) {
			return true;
		}
	}
	
	return false;
}

void GameScreen::paint(const std::vector<std::vector<MyObject*> >& vect_gameMap) {
	for(unsigned int y = 0; y < vect_gameMap.size(); y++) {
		for(unsigned int x = 0; x < vect_gameMap[y].size(); x++) {
			if( isInScreen(y, x) ) {
				vect_gameMap[y][x]->paint(y % ConfigClass::getHeight(), x % ConfigClass::getWidth());
			}
		}
	}
	
	player->paint();
}