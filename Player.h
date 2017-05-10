/* 
 * File:   Player.h
 * Author: petr
 *
 * Created on May 8, 2017, 6:47 PM
 */

#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"

class Player : public Entity {
public:
	Player(char mapSymbol, int health, int speed, int attackDmg, int attackSpeed);
	
private:
	
};

#endif /* PLAYER_H */

