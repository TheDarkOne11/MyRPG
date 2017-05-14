#ifndef MOB_H
#define MOB_H

#include "Enemy.h"


/**
 * Most common enemy.
 */
class Mob : public Enemy {
public:
	Mob(int ID, char mapSymbol, int health, int speed, 
			int attackDmg, int attackSpeed, int range);
	Mob(const Mob* temp);
	
	MyObject* clone() const override;

private:
	
};

#endif /* MOB_H */

