#ifndef ITEM_H
#define ITEM_H

#include "Info.h"

/**
 * Superclass for all Items.
 */
class Item {
public:
	enum ItemType {
		CONSUMABLE,	///< Item can be used only once
		WEAPON,		///< 
		PROTECTION	///<
	};
	
	Item();
	
protected:
	Info::Attributes attributes;
};

#endif /* ITEM_H */

