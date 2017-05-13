/* 
 * File:   Entity.h
 * Author: petr
 *
 * Created on May 8, 2017, 4:01 PM
 */

#ifndef ENTITY_H
#define ENTITY_H

#include "MyObject.h"
#include <vector>

/**
 * Super class of the Player and all Enemies.
 */
class Entity : public MyObject {
public:
	/**
	 * This constructor is used for setting up "template" instances of derived classes.
	 * @param ID
	 * @param mapSymbol what the entity looks like in the game
	 * @param health
	 * @param speed
	 * @param attackDmg
	 * @param attackSpeed
	 */
	Entity	(char mapSymbol, int health, int speed, 
			int attackDmg, int attackSpeed);
	
	/**
	 This constructor is used for cloning "templates" of derived classes.
	 * @param temp is a "template" instance of the derived class.
	 */
	Entity	(const Entity* temp);
	
	// TODO remove
	void printMap(std::vector< std::vector<MyObject*> >& vect_gameMap) {
		for(unsigned int y = 0; y < vect_gameMap.size(); y++) {
			for(unsigned int x = 0; x < vect_gameMap[y].size(); x++) {
				std::cerr << vect_gameMap[y][x]->getMapSymbol();
			}
			std::cerr << std::endl;
		}
		std::cerr << std::endl;
	}
	
	
	virtual void move(int newY, int newX);
	
	virtual void move(std::vector< std::vector<MyObject*> >& vect_gameMap, int pressedKey);
	
	virtual void attack(Entity* target);
	
	virtual void isAttacked(int damage);
	
protected:
	int health, speed;
	int attackDmg, attackSpeed;
	
private:
	int timeSinceAttack;
	static int lastID;
};

#endif /* ENTITY_H */

