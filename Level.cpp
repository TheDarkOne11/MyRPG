#include "Level.h"
#include <unistd.h>

Level::Level() {
	
}

Level::~Level() {
}

void Level::update() {
	
}

void Level::paint() {
	for(int y = 0; y < file.size(); y++) {
		for(int x = 0; x < file[y].size(); x++) {
			mvprintw(y, x, file[y][x].c_str());
		}
	}
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