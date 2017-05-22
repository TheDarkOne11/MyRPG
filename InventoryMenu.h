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
	
	InventoryMenu(Player* player);
	
	bool update();
	
	void paint(Screen* screen);
	
private:
	Menu invMenu, excessiveMenu;
	Player* player;
	MenuType currentType;
	bool changes;
	Item* selectedItem;
	
	void reloadInventory();
	
	void swap();
};

#endif /* INVENTORYMENU_H */

