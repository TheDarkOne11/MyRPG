#include "Entity.h"

Entity::Entity	(int ID, char mapSymbol, 
				int health, int speed, int attackDmg, int attackSpeed)
				: MyObject(ID, mapSymbol), health(health), speed(speed), 
				attackDmg(attackDmg), attackSpeed(attackSpeed)
{
	
}

void Entity::move(int newX, int newY)
{
	
}
	
void Entity::attack(Entity* target)
{
	
}

void Entity::isAttacked(int damage)
{
	
}