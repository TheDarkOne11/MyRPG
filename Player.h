/* 
 * File:   Player.h
 * Author: petr
 *
 * Created on May 8, 2017, 6:47 PM
 */

#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"
#include "UserInput.h"

class Player : public Entity {
public:
	enum Direction {
		UP = '^',
		DOWN = 'V',
		LEFT = '<',
		RIGHT = '>'
	};
	
	Player(char mapSymbol, int health, int speed, int attackDmg, int attackSpeed, int range);
	Player(const Player* temp);
	
	virtual void paint(const int y, const int x) override;
		
	virtual bool move(std::vector< std::vector<MyObject*> >& vect_levelMap, int pressedKey) override;
	
	virtual MyObject* clone() const override;
	
private:
	Direction currDirection;
};

#endif /* PLAYER_H */

