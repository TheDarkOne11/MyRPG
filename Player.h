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
	enum Direction {
		UP,
		DOWN,
		LEFT,
		RIGHT
	};
	
	Player(char mapSymbol, int health, int speed, int attackDmg, int attackSpeed);
	Player(const Player* temp);
	
	virtual void paint(const int y, const int x) override;
	
	virtual void move(int newY, int newX) override;
	
	virtual MyObject* clone() const override;
	
private:
	Direction currDirection;
};

#endif /* PLAYER_H */

