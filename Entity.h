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
			int attackDmg, int attackSpeed, int range);
	
	/**
	 This constructor is used for cloning "templates" of derived classes.
	 * @param temp is a "template" instance of the derived class.
	 */
	Entity	(const Entity* temp);
		
	// TODO remove
	/*void printMap(std::vector< std::vector<MyObject*> >& vect_gameMap) {
		for(unsigned int y = 0; y < vect_gameMap.size(); y++) {
			for(unsigned int x = 0; x < vect_gameMap[y].size(); x++) {
				std::cerr << vect_gameMap[y][x]->getMapSymbol();
			}
			std::cerr << std::endl;
		}
		std::cerr << std::endl;
	}*/
	
	/**
	 * Moves Entity to the new position.
	 * Updates gameMap accordingly.
	 * @param vect_gameMap is the 2D vector game map.
	 * @param newY is Y-coordinate of new position.
	 * @param newX is X-coordinate of new position.
	 * @return true if the Entity could move to new coordinates.
	 */
	virtual bool move(std::vector< std::vector<MyObject*> >& vect_gameMap, int newY, int newX);
	
	/**
	 * Moves Entity according to the pressed key.
	 * @param vect_gameMap is the 2D vector game map.
	 * @param pressedKey
	 * @return true if the Entity could move to new coordinates.
	 */
	virtual bool move(std::vector< std::vector<MyObject*> >& vect_gameMap, int pressedKey);
	
	virtual void attack(Entity* target);
	
	virtual void isAttacked(int damage);
	
	void addToMap(std::vector<std::vector<MyObject*> >& vect_gameMap, int y, int x) override;

	
protected:
	int health, speed;
	int attackDmg, attackSpeed, range;
	
	/**
	 * Entity stores the MyObject it stands on.
	 */
	std::pair<ObjectGroup, int> entityStandsOn;
	
private:
	int timeSinceAttack;
	static int lastID;
};

#endif /* ENTITY_H */

