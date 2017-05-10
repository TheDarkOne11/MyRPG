#include "Player.h"

Player::Player(char mapSymbol, int health, int speed, int attackDmg, int attackSpeed) 
			: Entity(mapSymbol, health, speed, attackDmg, attackSpeed) {
}

MyObject* Player::clone() const {
	std::cerr << "cloned" << std::endl;
	return new Player(mapSymbol, health, speed, attackDmg, attackSpeed);
}