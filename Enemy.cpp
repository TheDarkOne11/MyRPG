#include "Enemy.h"

Enemy::Enemy	(int ID, char mapSymbol, std::string name, int health, int speed, 
				int attackDmg, int attackSpeed, int range)
				: Entity(ID, mapSymbol, name, health, speed, attackDmg, attackSpeed, range)
{
}

Enemy::Enemy	(const Enemy* temp) : Entity(temp)
{
}

void Enemy::AI_update(LevelMap& vect_levelMap, const Player* player, MsgBox* msgBox) {
	move(vect_levelMap, getY() + 1, getX());
}

void Enemy::die(LevelMap& levelMap) {
	ground->addToMap(levelMap, y, x, false);
	ground = NULL;
}
