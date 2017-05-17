#include <sstream>

#include "Entity.h"
#include "Handler.h"

Entity::Entity	(int ID, char mapSymbol, std::string name, int health, int speed, 
				int attackDmg, int attackSpeed, int range)
				:	MyObject(ID, mapSymbol, MyObject::ENTITY, false, name), 
					attributes(health, speed, attackDmg, attackSpeed, range), 
					actionsMade(speed), ground(NULL)
{
}

Entity::Entity	(const Entity* temp)
				: MyObject(temp->ID, temp->mapSymbol, temp->group, temp->isPassable, temp->name), 
				attributes(temp->attributes), actionsMade(temp->actionsMade), ground(NULL)
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

bool Entity::alive() const {
	if(attributes.health <= 0) {
		return false;
	}
	
	
	return true;
}

void Entity::addToMap(LevelMap& vect_levelMap, int y, int x, bool removeFormer) {
	this->ground = vect_levelMap[y][x];
	this->MyObject::addToMap(vect_levelMap, y, x, removeFormer);
}

void Entity::checkGround() {
	// TODO Check ground for items
}

Info::Attributes Entity::getAttributes() const {
	return attributes;
}

bool Entity::findTarget(LevelMap& vect_levelMap, Direction direction, Entity*& target) {
	int addY = 0;
	int addX = 0;
	int currRange = attributes.range;
	
	switch(direction) {
		case UP:
			addY = -1;
			break;
		case DOWN:
			addY = 1;
			break;
		case LEFT:
			addX = -1;
			break;
		case RIGHT:
			addX = 1;
			break;
	}
	
	int currX = x + addX;
	int currY = y + addY;
	
	do {
		
		// Check bounds
		if(y < 0 || y >= (signed) vect_levelMap.size() || x < 0 || x >= (signed) vect_levelMap[y].size()) {
			return false;
		}
		
		MyObject* currObject = vect_levelMap[currY][currX];
		
		// If not passable static object found
		if(currObject->getGroup() == STATIC && !currObject->getPassable()) {
			return false;
		}
		
		// Entity found, potential target
		if(currObject->getGroup() == ENTITY) {
			target = dynamic_cast<Entity*> (currObject);
			return true;
		}
		
		currX += addX;
		currY += addY;
		currRange--;	
	} while(currRange > 0);
	
	return false;
}

void Entity::isAttacked(const Entity* attacker, MsgBox* msgBox) {
	Info::Attributes attr = attacker->getAttributes();
	attributes.health -= attr.attackDmg;
	
	std::stringstream ss;
	ss << attacker->name << " hit " << name << " for " << attr.attackDmg << " HP.";
	msgBox->addMsg(ss.str().c_str());
}

void Entity::attack(Entity* target, MsgBox* msgBox) {
	target->isAttacked(this, msgBox);
	actionsMade--;
}

bool Entity::hasActionsLeft() {
	if(actionsMade <= 0) {
		actionsMade = attributes.speed;
		return false;
	}
	
	return true;
}
