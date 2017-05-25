#ifndef INVENTORYMENU_H
#define INVENTORYMENU_H

#include "Player.h"
#include "Menu.h"

/**
 * Class handles special menu for manipulation of player inventory.
 */
class InventoryMenu {
public:
	enum MenuType {
		INVENTORY,		///< Menu for actual player inventory
		EXCESSIVE		///< Menu for all items that exceed player inventory
	};
	
	InventoryMenu();
	
	/**
	 * Update inventory menu.
	 * @return False if player wants out of Inventory menu.
	 */
	bool update();
	
	/**
	 * Paint inventory menu.
	 * @param screen
	 */
	void paint(Screen* screen);
	
	void setPlayer(Player* player);
	
private:
	Menu invMenu, excessiveMenu;
	Player* player;
	MenuType currentType;
	bool changes;				///< True if any changes were made.
	std::string currItemInfo;	///< String holding information about currently selected Item
	
	/**
	 * Reload inventory menues.
	 */
	void reloadInventory();
	
	/**
	 * Swap items between inventory and exceeding items.
	 */
	void swap();
};

#endif /* INVENTORYMENU_H */

