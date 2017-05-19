#include "Enemy.h"

Enemy::Enemy	(int ID, char mapSymbol, std::string name, Info::Attributes attr)
				: Entity(ID, mapSymbol, name, attr)
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

MyObject* Enemy::clone() const {
	return new Enemy(this);
}
