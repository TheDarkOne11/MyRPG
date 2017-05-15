#include "Info.h"

int Info::width = 0;
int Info::height = 0;
const std::string Info::pathDirMaps = "../res/maps";
const std::string Info::pathDirSaves = "../res/saves";
const std::string Info::pathNamesMaps = pathDirMaps + "/" + "mapNames.txt";
const std::string Info::pathNamesSaves = pathDirSaves + "/" + "savesNames.txt";

void Info::update() {
	getmaxyx(stdscr, height, width);
}

int Info::getHeight() {
	return height;
}

int Info::getWidth() {
	return width;
}