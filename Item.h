#ifndef ITEM_H
#define ITEM_H
#include <sstream>
#include "Info.h"

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
	Item(int ID, std::string name, ItemType type, Info::Attributes attr);
	
	/**
	 * This constructor is used for cloning "templates" of derived classes.
	 * @param temp is template instance
	 */
	Item(const Item* temp);
	
	virtual ~Item();
	
	/**
	 * Get string of all relevant information about this item.
	 * @return information string.
	 */
	virtual std::string getInfo() const;
	
	virtual Item* clone() const;
	
	virtual int getID() const;
	
	virtual std::string getName() const;
	
	virtual ItemType getType() const;
	
	virtual Info::Attributes getAttributes() const;
	
	virtual bool getEquiped() const;
	
	virtual void setEquiped(bool equiped);
	
protected:
	int ID;
	std::string name;
	ItemType type;
	Info::Attributes attributes;
	bool equiped;
};

#endif /* ITEM_H */

