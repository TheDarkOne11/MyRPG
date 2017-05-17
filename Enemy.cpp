#include "Enemy.h"

Enemy::Enemy	(int ID, char mapSymbol, std::string name, int health, int speed, 
				int attackDmg, int attackSpeed, int range)
				: Entity(ID, mapSymbol, name, health, speed, attackDmg, attackSpeed, range)
{
}

Enemy::Enemy	(const Enemy* temp) : Entity(temp)
{
}

void Enemy::AI_update(LevelMap& vect_levelMap, 
		const int playerY, const int playerX) {
	move(vect_levelMap, getY() + 1, getX());
}
