#ifndef ENTITY_H
#define ENTITY_H

#include <vector>
#include <sstream>
#include "MyObject.h"
#include "MsgBox.h"

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
	
	/**
	 * Entitie's attributes.
	 */
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
	void printMap(LevelMap& levelMap);
	
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
	
	/**
	 * Checks the ground Entity stands on.
	 */
	virtual void checkGround();
	
	/**
	 * Transfers items from one inventory to another.
	 * When invSize is specified, only items that exceed the source inventory are transfered.
	 * When invSize isn't specified, transfer all items.
	 * @param destination is the inventory to transfer items to.
	 * @param source is the inventory to transfer items from.
	 * @param invSize is the size of source inventory.
	 */
	virtual void transferItems(MyObject* destination, MyObject* source, const int invSize = -1);
	
	virtual bool hasActionsLeft();
	
	virtual bool alive() const;
	
	/**
	 * @return Entities attributes with applied changes from current state.
	 */
	virtual const Info::Attributes getCurrAttributes() const;
	
	virtual std::string getInfo() const;
	
protected:	
	/**
	 * Actions Entity has till the end of turn.
	 */
	int actionsLeft;
	
	/**
	 * All temporary effects (damage taken, buffs...) are stored here.
	 */
	Info::Attributes currState;
	
	/**
	 * Entity stores the MyObject it stands on.
	 */
	MyObject* ground;
};

#endif /* ENTITY_H */

