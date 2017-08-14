#ifndef ITEM_H
#define ITEM_H
#include <sstream>
#include "Info.h"
#include "Attributes.h"

/**
 * Superclass for all Items.
 */
class Item {
public:
	enum ItemType {
		CONSUMABLE,	///< Item can be used only once.
		USEABLE		///< Item provides bonuses as long as it is equiped.
	};
	
	/**
	 * This constructor is used for setting up "template" instances of derived classes.
	 * @param ID
	 * @param name
	 * @param type
	 * @param attr
	 */
	Item(int ID, std::string name, ItemType type, Attributes attr);
	
	/**
	 * This constructor is used for cloning "templates" of derived classes.
	 * @param temp is template instance
	 */
	Item(const Item* temp);
	
	virtual ~Item();
	
	/**
	 * Get string of all relevant information about this item.
	 * @return Information string.
	 */
	virtual std::string getInfo() const;
	
	/**
	 * @return Clone of Item.
	 */
	virtual Item* clone() const;
	
	virtual int getID() const;
	
	virtual std::string getName() const;
	
	virtual ItemType getType() const;
	
	virtual Attributes getAttributes() const;
	
	/**
	 * @return True if equiped by the player.
	 */
	virtual bool getEquiped() const;
	
	virtual void setEquiped(bool equiped);
	
protected:
	int ID;					///< ID unique in the Item's type
	std::string name;		///< Name of the Item
	ItemType type;
	Attributes attributes;
	bool equiped;			///< True if item is equipped by the player
};

#endif /* ITEM_H */

