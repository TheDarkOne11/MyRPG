#include "Entity.h"

int Entity::lastID = 0;


Entity::Entity	(char mapSymbol, int health, int speed, 
				int attackDmg, int attackSpeed)
				: MyObject(lastID, mapSymbol, MyObject::ENTITY_ENEMY), health(health), 
				speed(speed), attackDmg(attackDmg), attackSpeed(attackSpeed)
{
	lastID++;
}

void Entity::move(int newY, int newX)
{
	x = newX;
	y = newY;
}
	
void Entity::attack(Entity* target)
{
	
}

void Entity::isAttacked(int damage)
{
	
}