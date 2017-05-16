#include "UserInput.h"

int UserInput::pressedKey;

void UserInput::update() {
	pressedKey = getch();
}

int UserInput::getPressedKey() {
	return pressedKey;
}