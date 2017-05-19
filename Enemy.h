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
	Enemy	(int ID, char mapSymbol, std::string name, Info::Attributes attr);
	
	/**
	 This constructor is used for cloning "templates" of derived classes.
	 * @param temp is a "template" instance of the derived class.
	 */
	Enemy	(const Enemy* temp);
	
	void die(LevelMap& levelMap);
		
	void AI_update(LevelMap& vect_levelMap, const Player* player, MsgBox* msgBox);
	
	MyObject* clone() const override;

};

#endif /* ENEMY_H */

