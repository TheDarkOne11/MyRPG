#include "Entity.h"
#include "Handler.h"

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
	MyObject* destination = vect_levelMap[newY][newX];
	// Check if entity moved
	if(y == newY && x == newX) {
		return true;
	}
	
	// Check for collision
	if(!destination->getPassable()) {
		// MyObject on new coordinates not passable. No move.
		return false;
	}
	
	// Update game map
	MyObject* currStandsOn = Handler::getMyObject(ground.first, ground.second);	
		// Old position of this Entity is swapped for the MyObject that Entity stood on
		currStandsOn->addToMap(vect_levelMap, y, x, false);
		
		// Entity is moved to new position on the map
		addToMap(vect_levelMap, newY, newX, true);
		
	
	checkGround();
		
	return true;
}
	
void Entity::attack(Entity* target)
{
	
}

void Entity::isAttacked(int damage)
{
	
}

bool Entity::alive() {
	if(health <= 0) {
		return false;
	}
	
	
	return true;
}

void Entity::addToMap(std::vector<std::vector<MyObject*> >& vect_levelMap, int y, int x, bool removeFormer) {
	MyObject* curr = vect_levelMap[y][x];
	this->ground = std::make_pair(curr->getGroup(), curr->getID());
	this->MyObject::addToMap(vect_levelMap, y, x, removeFormer);
}

void Entity::checkGround() {
	// Check ground for items
}
