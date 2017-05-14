#include "Entity.h"
#include "Info.h"

Entity::Entity	(int ID, char mapSymbol, int health, int speed, 
				int attackDmg, int attackSpeed, int range)
				: MyObject(ID, mapSymbol, MyObject::ENTITY, false), health(health), 
				speed(speed), attackDmg(attackDmg), attackSpeed(attackSpeed), range(range)
{
}

Entity::Entity	(const Entity* temp)
				: MyObject(temp->ID, temp->mapSymbol, temp->group, temp->isPassable), 
				health(temp->health), speed(temp->speed), attackDmg(temp->attackDmg), 
				attackSpeed(temp->attackSpeed), range(temp->range)
{
}

bool Entity::move(std::vector< std::vector<MyObject*> >& vect_levelMap, int newY, int newX)
{
	MyObject* newPos = vect_levelMap[newY][newX];
	// Check if entity moved
	if(y == newY && x == newX) {
		return true;
	}
	
	// Check for collision
	if(!newPos->getPassable()) {
		// MyObject on new coordinates not passable. No move.
		return false;
	}
	
	// Update game map
	//TODO
	MyObject* oldPos = Info::getMyObject(entityStandsOn.first, entityStandsOn.second);
	entityStandsOn = std::make_pair(newPos->getGroup(), newPos->getID());
	delete newPos;
	vect_levelMap[newY][newX] = this;
	vect_levelMap[y][x] = oldPos;
	
	
	// Update entity coordinates
	x = newX;
	y = newY;
	
	return true;
}

bool Entity::move(std::vector< std::vector<MyObject*> >& vect_levelMap, int pressedKey) {
	return true;
}
	
void Entity::attack(Entity* target)
{
	
}

void Entity::isAttacked(int damage)
{
	
}

void Entity::addToMap(std::vector<std::vector<MyObject*> >& vect_levelMap, int y, int x) {
	MyObject* curr = vect_levelMap[y][x];
	this->entityStandsOn = std::make_pair(curr->getGroup(), curr->getID());
	MyObject::addToMap(vect_levelMap, y, x);
	delete curr;
}