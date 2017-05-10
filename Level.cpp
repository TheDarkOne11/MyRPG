#include "Level.h"

Level::Level() {
	player = ConfigClass::getPlayer();
	player->addObject(5, 10);
}

Level::~Level() {
}

void Level::update() {
	switch(Game::getPressedKey()) {
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
	for(int y = 0; y < file.size(); y++) {
		for(int x = 0; x < file[y].size(); x++) {
			mvprintw(y, x, file[y][x].c_str());
		}
	}
	
	player->paint();
}

void Level::fillMap(int h, int w) {
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