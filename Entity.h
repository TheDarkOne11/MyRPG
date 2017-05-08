/* 
 * File:   Entity.h
 * Author: petr
 *
 * Created on May 8, 2017, 4:01 PM
 */

#ifndef ENTITY_H
#define ENTITY_H

#include "MyObject.h"

/**
 * Super class of the Player and all Enemies.
 */
class Entity : public MyObject {
protected:
	int health, speed;
	int attackDmg, attackSpeed;
	
private:
	int timeSinceAttack;
	
public:
	
	/**
	 * 
	 * @param ID
	 * @param x
	 * @param y
	 * @param mapSymbol what the entity looks like in the game
	 * @param health
	 * @param speed
	 * @param attackDmg
	 * @param attackSpeed
	 */
	Entity	(int ID, int x, int y, char mapSymbol, 
			int health, int speed, int attackDmg, int attackSpeed);
	
	
	virtual void move(int newX, int newY);
	
	virtual void attack(Entity* target);
	
	virtual void isAttacked(int damage);
};

#endif /* ENTITY_H */

