#include "Player.h"

Player::Player(char mapSymbol, int health, int speed, int attackDmg, int attackSpeed) 
			: Entity(mapSymbol, health, speed, attackDmg, attackSpeed) 
{
}

Player::Player(const Player* temp) : Entity(temp), currDirection(RIGHT)
{
}

void Player::paint(const int y, const int x) {
	switch(currDirection) {
		case(UP):
			mvprintw(y, x, "%c", '^');
			break;
		case(DOWN):
			mvprintw(y, x, "%c", 'V');
			break;
		case(LEFT):
			mvprintw(y, x, "%c", '<');
			break;
		case(RIGHT):
			mvprintw(y, x, "%c", '>');
			break;
	}
}

void Player::move(int newY, int newX) {
	int currY = y;
	int currX = x;
	
	// Move
	Entity::move(newY, newX);
	
	// Change direction
	if(currY < newY) {
		currDirection = DOWN;
	} else if(currY > newY) {
		currDirection = UP;
	} else if(currX < newX) {
		currDirection = RIGHT;
	} else if(currX > newX) {
		currDirection = LEFT;
	}
}

MyObject* Player::clone() const {
	return new Player(this);
}