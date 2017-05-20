#ifndef ENTITY_H
#define ENTITY_H

#include "MyObject.h"
#include "MsgBox.h"
#include <vector>

/**
 * Super class of the Player and all Enemies.
 */
class Entity : public MyObject {
public:
	enum Direction {
		UP = '^',
		DOWN = 'V',
		LEFT = '<',
		RIGHT = '>'
	};
	
	Info::Attributes attributes;
	
	/**
	 * This constructor is used for setting up "template" instances of derived classes.
	 * @param ID
	 * @param mapSymbol what the entity looks like in the game
	 * @param health
	 * @param speed
	 * @param attackDmg
	 * @param attackSpeed
	 */
	Entity	(int ID, char mapSymbol, std::string name, Info::Attributes attr);
	
	virtual ~Entity();
		
	/**
	 This constructor is used for cloning "templates" of derived classes.
	 * @param temp is a "template" instance of the derived class.
	 */
	Entity	(const Entity* temp);
		
	// TODO remove
	void printMap(LevelMap& levelMap) {
		for(unsigned int y = 0; y < levelMap.size(); y++) {
			for(unsigned int x = 0; x < levelMap[y].size(); x++) {
				std::cerr << levelMap[y][x]->getMapSymbol();
			}
			std::cerr << std::endl;
		}
		std::cerr << std::endl;
	}
	
	void addToMap(LevelMap& levelMap, int y, int x, bool removeFormer) override;
	
	/**
	 * Moves Entity to the new position.
	 * Updates gameMap accordingly.
	 * @param levelMap is the 2D vector game map.
	 * @param newY is Y-coordinate of new position.
	 * @param newX is X-coordinate of new position.
	 * @return true if the Entity could move to new coordinates.
	 */
	virtual bool move(LevelMap& levelMap, int newY, int newX);
	
	/**
	 * Searches for target Entity in given direction.
	 * Stops at impassable positions.
	 * @param levelMap
	 * @param direction says in what direction to look.
	 * @param target is the pointer to the found entity.
	 * @return true if found
	 */
	virtual bool findTarget(LevelMap& levelMap, Direction direction, Entity*& target, 
			const int yPos, const int xPos);
	
	virtual void attack(Entity* target, MsgBox* msgBox);
	
	virtual void isAttacked(const Entity* attacker, MsgBox* msgBox);
	
	virtual bool hasActionsLeft();
	
	virtual bool alive() const;
	
	/**
	 * Checks the ground Entity stands on.
	 */
	virtual void checkGround();
	
protected:	
	int actionsLeft;
	
	/**
	 * Entity stores the MyObject it stands on.
	 */
	MyObject* ground;
};

#endif /* ENTITY_H */

