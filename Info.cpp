#include "Info.h"

int Info::width = 0;
int Info::height = 0;

void Info::update() {
	getmaxyx(stdscr, height, width);
}

int Info::getHeight() {
	return height;
}

int Info::getWidth() {
	return width;
}