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
	Entity	(int ID, char mapSymbol, int health, int speed, 
			int attackDmg, int attackSpeed, int range);
	
	virtual ~Entity();
	
	/**
	 This constructor is used for cloning "templates" of derived classes.
	 * @param temp is a "template" instance of the derived class.
	 */
	Entity	(const Entity* temp);
		
	// TODO remove
	void printMap(LevelMap& vect_levelMap) {
		for(unsigned int y = 0; y < vect_levelMap.size(); y++) {
			for(unsigned int x = 0; x < vect_levelMap[y].size(); x++) {
				std::cerr << vect_levelMap[y][x]->getMapSymbol();
			}
			std::cerr << std::endl;
		}
		std::cerr << std::endl;
	}
	
	/**
	 * Moves Entity to the new position.
	 * Updates gameMap accordingly.
	 * @param vect_levelMap is the 2D vector game map.
	 * @param newY is Y-coordinate of new position.
	 * @param newX is X-coordinate of new position.
	 * @return true if the Entity could move to new coordinates.
	 */
	virtual bool move(LevelMap& vect_levelMap, int newY, int newX);
	
	virtual void attack(Entity* target);
	
	virtual void isAttacked(int damage);
	
	virtual bool alive();
	
	/**
	 * Checks the ground Entity stands on.
	 */
	virtual void checkGround();
	
	void addToMap(LevelMap& vect_levelMap, int y, int x, bool removeFormer) override;
	
protected:
	Info::Attributes attributes;
	
	/**
	 * How many actions Entity did this turn
	 */
	int actionsMade;
	
	/**
	 * Entity stores the MyObject it stands on.
	 */
	MyObject* ground;
	
private:
	int timeSinceAttack;
};

#endif /* ENTITY_H */

