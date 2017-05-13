#include "Entity.h"

int Entity::lastID = 0;


Entity::Entity	(char mapSymbol, int health, int speed, 
				int attackDmg, int attackSpeed)
				: MyObject(lastID, mapSymbol, MyObject::ENTITY), health(health), 
				speed(speed), attackDmg(attackDmg), attackSpeed(attackSpeed)
{
	lastID++;
}

Entity::Entity	(const Entity* temp)
				: MyObject(lastID, temp->mapSymbol, MyObject::ENTITY), 
				health(temp->health), speed(temp->speed), attackDmg(temp->attackDmg), 
				attackSpeed(temp->attackSpeed)
{
}

void Entity::move(int newY, int newX)
{
	x = newX;
	y = newY;
}

void Entity::move(std::vector< std::vector<MyObject*> >& vect_gameMap, int pressedKey) {
}
	
void Entity::attack(Entity* target)
{
	
}

void Entity::isAttacked(int damage)
{
	
}