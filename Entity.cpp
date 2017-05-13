#include "Entity.h"

int Entity::lastID = 0;


Entity::Entity	(char mapSymbol, int health, int speed, 
				int attackDmg, int attackSpeed)
				: MyObject(lastID, mapSymbol, MyObject::ENTITY, false), health(health), 
				speed(speed), attackDmg(attackDmg), attackSpeed(attackSpeed)
{
	lastID++;
}

Entity::Entity	(const Entity* temp)
				: MyObject(lastID, temp->mapSymbol, temp->group, temp->isPassable), 
				health(temp->health), speed(temp->speed), attackDmg(temp->attackDmg), 
				attackSpeed(temp->attackSpeed)
{
}

bool Entity::move(std::vector< std::vector<MyObject*> >& vect_gameMap, int newY, int newX)
{
	
	
	// Update entity coordinates
	x = newX;
	y = newY;
}

bool Entity::move(std::vector< std::vector<MyObject*> >& vect_gameMap, int pressedKey) {
}
	
void Entity::attack(Entity* target)
{
	
}

void Entity::isAttacked(int damage)
{
	
}