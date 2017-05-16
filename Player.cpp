#include "Player.h"

Player::Player(int ID, char mapSymbol, int health, int speed, int attackDmg, int attackSpeed, int range) 
			: Entity(ID, mapSymbol, health, speed, attackDmg, attackSpeed, range), doorFound(false)
{
}

Player::Player(const Player* temp) : Entity(temp), currDirection(RIGHT), doorFound(false)
{
}

void Player::paint(Screen* screen, const int y, const int x) {
	mvwprintw(screen->getCurrScreen(), y, x, "%c", currDirection);
}

bool Player::move(LevelMap& vect_levelMap, int pressedKey) {
	int newY = y;
	int newX = x;
	
	// Move according to the pressedKey
	switch(pressedKey) {
		case(UserInput::K_UP):
			newY -= 1;
			currDirection = UP;
			break;
		case(UserInput::K_DOWN):
			newY += 1;
			currDirection = DOWN;
			break;
		case(UserInput::K_LEFT):
			newX -=1;
			currDirection = LEFT;
			break;
		case(UserInput::K_RIGHT):
			newX += 1;
			currDirection = RIGHT;
			break;
		default:
			return false;
			break;
	}
	
	if(y != newY || x != newX) {
		//TODO Remove
		//printMap(vect_levelMap);
	}
	
	return Entity::move(vect_levelMap, newY, newX);
}

MyObject* Player::clone() const {
	return new Player(this);
}

void Player::checkGround() {
	Entity::checkGround();
	
	if(ground->getID() == Info::ID_Door) {
		doorFound = true;
	}
}

bool Player::getDoorFound() {
	return doorFound;
}

void Player::prepareToNextLevel() {
	doorFound = false;
	delete ground;
	ground = NULL;
}
