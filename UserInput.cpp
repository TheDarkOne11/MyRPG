#include "UserInput.h"

int UserInput::pressedKey;

UserInput::UserInput() {
}

void UserInput::update() {
	pressedKey = getch();
}

int UserInput::getPressedKey() {
	return pressedKey;
}