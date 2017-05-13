#include "Entity.h"
#include "ConfigClass.h"

int Entity::lastID = 0;


Entity::Entity	(char mapSymbol, int health, int speed, 
				int attackDmg, int attackSpeed, int range)
				: MyObject(lastID, mapSymbol, MyObject::ENTITY, false), health(health), 
				speed(speed), attackDmg(attackDmg), attackSpeed(attackSpeed), range(range)
{
	lastID++;
}

Entity::Entity	(const Entity* temp)
				: MyObject(temp->ID, temp->mapSymbol, temp->group, temp->isPassable), 
				health(temp->health), speed(temp->speed), attackDmg(temp->attackDmg), 
				attackSpeed(temp->attackSpeed), range(temp->range)
{
}

bool Entity::move(std::vector< std::vector<MyObject*> >& vect_gameMap, int newY, int newX)
{
	MyObject* newPos = vect_gameMap[newY][newX];
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
	MyObject* oldPos = ConfigClass::getMyObject(entityStandsOn.first, entityStandsOn.second);
	entityStandsOn = std::make_pair(newPos->getGroup(), newPos->getID());
	delete newPos;
	vect_gameMap[newY][newX] = this;
	vect_gameMap[y][x] = oldPos;
	
	
	// Update entity coordinates
	x = newX;
	y = newY;
	
	return true;
}

bool Entity::move(std::vector< std::vector<MyObject*> >& vect_gameMap, int pressedKey) {
	return true;
}
	
void Entity::attack(Entity* target)
{
	
}

void Entity::isAttacked(int damage)
{
	
}

void Entity::addToMap(std::vector<std::vector<MyObject*> >& vect_gameMap, int y, int x) {
	MyObject* curr = vect_gameMap[y][x];
	this->entityStandsOn = std::make_pair(curr->getGroup(), curr->getID());
	MyObject::addToMap(vect_gameMap, y, x);
	delete curr;
}