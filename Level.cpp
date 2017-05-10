#include "Level.h"

Level::Level() {
	// Get player from ConfigClass
	player = dynamic_cast<Player*> ( ConfigClass::getPlayer() );
	player->addObject(3, 10);
}

Level::~Level() {
	delete player;
	
	for(unsigned int y = 0; y < vect_gameMap.size(); y++) {
		for(unsigned int x = 0; x < vect_gameMap[y].size(); x++) {
			delete vect_gameMap[y][x];
		}
	}
}

void Level::update() {
	switch(UserInput::getPressedKey()) {
		case(KEY_UP):
			player->move(player->getY() - 1, player->getX());
			break;
		case(KEY_DOWN):
			player->move(player->getY() + 1, player->getX());
			break;
		case(KEY_LEFT):
			player->move(player->getY(), player->getX() - 1);
			break;
		case(KEY_RIGHT):
			player->move(player->getY(), player->getX() + 1);
			break;
	}
}

void Level::paint() {
	for(unsigned int y = 0; y < vect_gameMap.size(); y++) {
		for(unsigned int x = 0; x < vect_gameMap[y].size(); x++) {
			vect_gameMap[y][x]->paint();
		}
	}
	
	player->paint();
}

void Level::fillMap(int h, int w) {
	//TODO Read map from file instead of hardcoding it
	for(int y = 0; y < h; y++) {
		std::vector<MyObject*> row;
		for(int x = 0; x < w; x++) {
			MyObject* tmp;
			if(y == 0 || y == h -1 || x == 0 || x == w - 1) {
				tmp = ConfigClass::getMyObject('#');
			} else {
				tmp = ConfigClass::getMyObject(' ');
			}
			row.push_back(tmp);
			tmp->addObject(y, x);
		}
		vect_gameMap.push_back(row);
	}
}