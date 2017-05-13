#include "Enemy.h"

Enemy::Enemy	(char mapSymbol, int health, int speed, 
				int attackDmg, int attackSpeed, int range)
				: Entity(mapSymbol, health, speed, attackDmg, attackSpeed, range)
{
}

Enemy::Enemy	(const Enemy* temp) : Entity(temp)
{
}

void Enemy::AI_update(std::vector<std::vector<MyObject*> >& vect_gameMap, 
		const int playerY, const int playerX) {
	move(vect_gameMap, getY() + 1, getX());
}
