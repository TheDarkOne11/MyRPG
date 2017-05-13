#include "Player.h"

Player::Player(char mapSymbol, int health, int speed, int attackDmg, int attackSpeed, int range) 
			: Entity(mapSymbol, health, speed, attackDmg, attackSpeed, range) 
{
}

Player::Player(const Player* temp) : Entity(temp), currDirection(RIGHT)
{
}

void Player::paint(const int y, const int x) {
	mvprintw(y, x, "%c", currDirection);
}

bool Player::move(std::vector<std::vector<MyObject*> >& vect_gameMap, int pressedKey) {
	int newY = y;
	int newX = x;
	
	switch(pressedKey) {
		case(KEY_UP):
			newY -= 1;
			currDirection = UP;
			break;
		case(KEY_DOWN):
			newY += 1;
			currDirection = DOWN;
			break;
		case(KEY_LEFT):
			newX -=1;
			currDirection = LEFT;
			break;
		case(KEY_RIGHT):
			newX += 1;
			currDirection = RIGHT;
			break;
		default:
			return false;
			break;
	}
	
	return Entity::move(vect_gameMap, newY, newX);
}

MyObject* Player::clone() const {
	return new Player(this);
}