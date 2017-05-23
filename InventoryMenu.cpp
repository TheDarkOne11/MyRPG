#include "InventoryMenu.h"

InventoryMenu::InventoryMenu() : invMenu("Inventory"), excessiveMenu("Excessive items"),
		currentType(INVENTORY), changes(true), currItemInfo("")
{
	invMenu.setScreenOffset(0, -30);
	excessiveMenu.setScreenOffset(0, 30);
}

void InventoryMenu::paint(Screen* screen) {
	std::stringstream ss, ss2, ss3;
	InvList& inv = player->getInventory();
	
	//Paint inventory menu
	screen->setCurrScreen(screen->ATTR_INV);
	invMenu.paint(screen);
	excessiveMenu.paint(screen);
	screen->sRefresh();
	
	// Paint info menu
	screen->setCurrScreen(screen->INFO);
	ss << "Press " << (char) UserInput::K_SWAP << " to swap currently selected items in both menus.";
	ss2 << "Press " << (char) UserInput::K_EQUIP << " to equip an item selected in Inventory.";
	ss3 << "Currently selected " << currItemInfo;
	
	mvwprintw(screen->getCurrScreen(), 0, 0, "Select menu to scroll through using LEFT/ RIGHT arrow keys. Press ESC to return/ continue.");
	mvwprintw(screen->getCurrScreen(), 1, 0, ss.str().c_str());
	mvwprintw(screen->getCurrScreen(), 2, 0, ss2.str().c_str());
	
	// Paint selected item info
	mvwprintw(screen->getCurrScreen(), 3, 0, ss3.str().c_str());
}

bool InventoryMenu::update() {	
	InvList& inv = player->getInventory();
	int index;
	
	// Switch menus, equip, swap...
	switch(UserInput::getPressedKey()) {
		case(UserInput::K_LEFT):
		case(UserInput::K_RIGHT):
			currentType = (MenuType) !currentType;
			break;
		case(UserInput::K_SWAP):
			swap();
			changes = true;			
			break;
		case(UserInput::K_EQUIP):
			changes = true;
			if(!inv.empty()) {
				// Get currently selected item
				index = invMenu.getCurrentChoice();
				player->equipItem( index);
			}
			break;
		case(UserInput::K_ESC):
			// Return back
			changes = true;
			currentType = INVENTORY;
			return false;
	}
	
	// Changes occured - swaps, equips, leaving inventory
	if(changes) {
		changes = false;
		reloadInventory();
	}
	
	// Update currently selected menu
	switch(currentType){
		case(INVENTORY):
			invMenu.update();
			break;
		case(EXCESSIVE):
			excessiveMenu.update();
			break;
	}
	
	if(!inv.empty()) {
		if(currentType == INVENTORY) {
			currItemInfo = inv[invMenu.getCurrentChoice()]->getInfo();
		} else if(currentType == EXCESSIVE && (signed) inv.size() > player->getCurrAttributes().invSpace) {
			currItemInfo = inv[excessiveMenu.getCurrentChoice()]->getInfo();
		}
	}
	
	return true;
}

void InventoryMenu::reloadInventory() {
	ChoiceVect inventoryList;
	ChoiceVect excessiveList;
	InvList& inv = player->getInventory();
	
	for(int i = 0; i < (signed) inv.size(); i++) {
		std::string currName = inv.at(i)->getName();
		
		// If item is equipped, indicate it
		if(inv.at(i)->getEquiped()) {
			currName.append(" (Eq)");
		}
		
		// Add item name to the list it belongs to
		if(i < player->getCurrAttributes().invSpace)
			inventoryList.push_back(std::make_pair(currName, i));
		else
			excessiveList.push_back(std::make_pair(currName, i));
	}
	invMenu.setChoices(inventoryList);
	excessiveMenu.setChoices(excessiveList);
}

void InventoryMenu::swap() {
	InvList& inv = player->getInventory();
	
	if((signed) inv.size() < player->getCurrAttributes().invSpace) {
		// Nothing to swap, return
		return;
	}
	
	int indexI = invMenu.getCurrentChoice();
	int indexE = excessiveMenu.getCurrentChoice();
		
	Item* tmp = inv.at(indexI);
	
	// Unequip item if it is equipped
	if(tmp->getEquiped()) {
		player->equipItem(indexI);
	}
	
	// Swap items
	inv.at(indexI) = inv.at(indexE);
	inv.at(indexE) = tmp;
}

void InventoryMenu::setPlayer(Player* player) {
	this->player = player;
}
