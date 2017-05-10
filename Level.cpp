#include "Level.h"

Level::Level() {
	// Get player from ConfigClass
	player = dynamic_cast<Player*> ( ConfigClass::getPlayer() );
	player->addObject(3, 10);
}

Level::~Level() {
	delete player;
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
	for(unsigned int y = 0; y < file.size(); y++) {
		for(unsigned int x = 0; x < file[y].size(); x++) {
			mvprintw(y, x, file[y][x].c_str());
		}
	}
	
	player->paint();
}

void Level::fillMap(int h, int w) {
	//TODO Read map from file instead of hardcoding it
	for(int y = 0; y < h; y++) {
		std::vector<std::string> row;
		for(int x = 0; x < w; x++) {
			std::string s;
			if(y == 0 || y == h -1 || x == 0 || x == w - 1) {
				s = "#";
			} else {
				s = " ";
			}
			row.push_back(s);
		}
		file.push_back(row);
	}
	
	
}