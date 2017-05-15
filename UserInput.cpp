#include "UserInput.h"

int UserInput::pressedKey;
int UserInput::width = 0;
int UserInput::height = 0;

void UserInput::update() {
	pressedKey = getch();
	getmaxyx(stdscr, height, width);
}

int UserInput::getPressedKey() {
	return pressedKey;
}

int UserInput::getHeight() {
	return height;
}

int UserInput::getWidth() {
	return width;
}