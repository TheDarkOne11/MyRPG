#include "Player.h"

Player::Player(char mapSymbol, int health, int speed, int attackDmg, int attackSpeed) 
			: Entity(mapSymbol, health, speed, attackDmg, attackSpeed) 
{
}

Player::Player(const Player* temp) : Entity(temp) 
{
}

MyObject* Player::clone() const {
	return new Player(this);
}