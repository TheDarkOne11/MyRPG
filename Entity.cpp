#include "Entity.h"
#include "Handler.h"

Entity::Entity	(int ID, char mapSymbol, int health, int speed, 
				int attackDmg, int attackSpeed, int range)
				:	MyObject(ID, mapSymbol, MyObject::ENTITY, false), 
					attributes(health, speed, attackDmg, attackSpeed, range), 
					actionsMade(0), ground(NULL)
{
}

Entity::Entity	(const Entity* temp)
				: MyObject(temp->ID, temp->mapSymbol, temp->group, temp->isPassable), 
				attributes(temp->attributes), actionsMade(0), ground(NULL)
{
}

Entity::~Entity() {
	if(ground != NULL) {
		delete ground;
	}
}

bool Entity::move(LevelMap& vect_levelMap, int newY, int newX)
{
	// Check if entity moved
	if(y == newY && x == newX) {
		return true;
	}
	
	// Check for collision
	if(!vect_levelMap[newY][newX]->getPassable()) {
		// MyObject on new coordinates not passable. No move.
		return false;
	}
	
	// Update game map
		// Old position of this Entity is swapped for the MyObject that Entity stood on
		ground->addToMap(vect_levelMap, y, x, false);
		
		// Entity is moved to new position on the map
		this->addToMap(vect_levelMap, newY, newX, false);
		
	
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
	if(attributes.health <= 0) {
		return false;
	}
	
	
	return true;
}

void Entity::addToMap(std::vector<std::vector<MyObject*> >& vect_levelMap, int y, int x, bool removeFormer) {
	MyObject* curr = vect_levelMap[y][x];
	this->ground = curr;
	this->MyObject::addToMap(vect_levelMap, y, x, removeFormer);
}

void Entity::checkGround() {
	// TODO Check ground for items
}
