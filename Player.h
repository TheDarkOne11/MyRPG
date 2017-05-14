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
	
	Player(int ID, char mapSymbol, int health, int speed, int attackDmg, int attackSpeed, int range);
	Player(const Player* temp);
	
	virtual void paint(const int y, const int x) override;
		
	/**
	 * Moves Entity according to the pressed key.
	 * @param vect_levelMap is the 2D vector game map.
	 * @param pressedKey
	 * @return true if the Entity could move to new coordinates.
	 */
	virtual bool move(std::vector< std::vector<MyObject*> >& vect_levelMap, int pressedKey);
	
	/**
	 * Checks ground for items and for doors to next level;
	 */
	void checkGround() override;
	
	bool getDoorFound();
	
	void prepareToNextLevel();
	
	virtual MyObject* clone() const override;
	
private:
	Direction currDirection;
	bool doorFound;
};

#endif /* PLAYER_H */

