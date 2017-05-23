#ifndef INVENTORYMENU_H
#define INVENTORYMENU_H

#include "Player.h"
#include "Menu.h"

class InventoryMenu {
public:
	enum MenuType {
		INVENTORY,
		EXCESSIVE
	};
	
	InventoryMenu();
	
	bool update();
	
	void paint(Screen* screen);
	
	void setPlayer(Player* player);
	
private:
	Menu invMenu, excessiveMenu;
	Player* player;
	MenuType currentType;
	bool changes;
	std::string currItemInfo;
	
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

