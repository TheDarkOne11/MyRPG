#include "Enemy.h"

Enemy::Enemy	(int ID, char mapSymbol, int health, int speed, 
				int attackDmg, int attackSpeed, int range)
				: Entity(ID, mapSymbol, health, speed, attackDmg, attackSpeed, range)
{
}

Enemy::Enemy	(const Enemy* temp) : Entity(temp)
{
}

void Enemy::AI_update(std::vector<std::vector<MyObject*> >& vect_levelMap, 
		const int playerY, const int playerX) {
	move(vect_levelMap, getY() + 1, getX());
}
