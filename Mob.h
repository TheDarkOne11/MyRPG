/* 
 * File:   Mob.h
 * Author: petr
 *
 * Created on May 12, 2017, 5:46 PM
 */

#ifndef MOB_H
#define MOB_H

#include "Enemy.h"


/**
 * Most common enemy.
 */
class Mob : public Enemy {
public:
	Mob(char mapSymbol, int health, int speed, 
			int attackDmg, int attackSpeed, int range);
	Mob(const Mob* temp);
	
	MyObject* clone() const override;

private:
	
};

#endif /* MOB_H */

