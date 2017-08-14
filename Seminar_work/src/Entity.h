#ifndef ENTITY_H
#define ENTITY_H

#include <vector>
#include <sstream>
#include "MyObject.h"
#include "MsgBox.h"
#include "Attributes.h"

/**
 * Super class of the Player and all Enemies.
 * Anything that moves is an Entity.
 */
class Entity : public MyObject {
public:
	enum Direction {
		UP = '^',
		DOWN = 'V',
		LEFT = '<',
		RIGHT = '>'
	};
	
	Attributes attributes;	///< Entitie's attributes.
	
	/**
	 * This constructor is used for setting up "template" instances of derived classes.
	 * @param ID
	 * @param mapSymbol
	 * @param name
	 * @param attr are this Entitie's attributes.
	 */
	Entity	(int ID, char mapSymbol, std::string name, Attributes attr);
	
	virtual ~Entity();
		
	/**
	 This constructor is used for cloning "templates" of derived classes.
	 * @param temp is a "template" instance of the derived class.
	 */
	Entity	(const Entity* temp);
	
	/**
	 * Used when adding Entity to levelMap in random position.
	 * @param levelMap
	 * @param y
	 * @param x
	 * @param removeFormer true if the MyObject in y, x position should be removed.
	 */
	void addToMap(LevelMap& levelMap, const int y, const int x, const bool removeFormer) override;
	
	/**
	 * Save Entity info in a file.
	 * @param file
	 */
	void save(std::ofstream& file) const override;
	
	/**
	 * Load Entity info from a file.
	 * @param file
	 */
	void load(std::ifstream& file) override;
	
	/**
	 * Moves Entity to the new position.
	 * Updates gameMap accordingly.
	 * @param levelMap is the 2D vector game map.
	 * @param newY is Y-coordinate of new position.
	 * @param newX is X-coordinate of new position.
	 * @return True if the Entity could move to new coordinates.
	 */
	virtual bool move(LevelMap& levelMap, const int newY, const int newX);
	
	/**
	 * Searches for target Entity in given direction.
	 * Stops at impassable positions.
	 * @param levelMap
	 * @param direction says in what direction to look.
	 * @param target is the pointer to the found entity.
	 * @return True if found
	 */
	virtual bool findTarget(const LevelMap& levelMap, const Direction direction, Entity*& target, 
			const int yPos, const int xPos) const;
	
	/**
	 * This Entity attacks another Entity.
	 * @param target is the Entity to attack.
	 * @param msgBox
	 */
	virtual void attack(Entity* target, MsgBox* msgBox);
	
	/**
	 * This Entity is attacked by another Entity
	 * @param attacker is the Entity that attacked this Entity.
	 * @param msgBox
	 */
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
	
	/**
	 * Equips/ Unequips an item.
	 * @param index is the index of Item in inventory to equip/ unequip.
	 */
	virtual void equipItem(const int index);
	
	/**
	 * Check if this Entity has any actions left. If not, reset actionsLeft variable.
	 * @return True if Entity has any actions left.
	 */
	virtual bool hasActionsLeft();
	
	virtual bool alive() const;
	
	/**
	 * @return Entities attributes with applied changes from current state.
	 */
	virtual const Attributes getCurrAttributes() const;
	
	/**
	 * @return All important information about this Entity.
	 */
	virtual std::string getInfo() const;
	
protected:	
	/**
	 * Actions Entity has till the end of turn.
	 */
	int actionsLeft;
	
	/**
	 * All temporary effects (damage taken, buffs...) are stored here.
	 */
	Attributes currState;
	
	/**
	 * Entity stores the MyObject it stands on.
	 */
	MyObject* ground;
};

#endif /* ENTITY_H */

