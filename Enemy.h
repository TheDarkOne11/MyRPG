/* 
 * File:   Enemy.h
 * Author: petr
 *
 * Created on May 13, 2017, 8:29 PM
 */

#ifndef ENEMY_H
#define ENEMY_H

#include "Entity.h"
#include "Player.h"

class Enemy : public Entity {
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
	Enemy	(char mapSymbol, int health, int speed, 
			int attackDmg, int attackSpeed, int range);
	
	/**
	 This constructor is used for cloning "templates" of derived classes.
	 * @param temp is a "template" instance of the derived class.
	 */
	Enemy	(const Enemy* temp);
	
	void AI_update(std::vector< std::vector<MyObject*> >& vect_gameMap, 
			const int playerY, const int playerX);
	
private:

};

#endif /* ENEMY_H */

