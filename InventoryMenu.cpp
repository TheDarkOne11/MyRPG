#include "InventoryMenu.h"

InventoryMenu::InventoryMenu(Player* player) : invMenu("Inventory"), excessiveMenu("Excessive items"),
		player(player), currentType(INVENTORY), changes(true), selectedItem(NULL)
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
	ss3 << "Currently selected ";
	
	mvwprintw(screen->getCurrScreen(), 0, 0, "Select menu to scroll through using LEFT/ RIGHT arrow keys. Press ESC to return/ continue.");
	mvwprintw(screen->getCurrScreen(), 1, 0, ss.str().c_str());
	mvwprintw(screen->getCurrScreen(), 2, 0, ss2.str().c_str());
	
	// Paint selected item info
	if(selectedItem != NULL) {
		 ss3 << selectedItem->getInfo();
	}
	mvwprintw(screen->getCurrScreen(), 3, 0, ss3.str().c_str());
}

bool InventoryMenu::update() {	
	InvList& inv = player->getInventory();
	if(changes) {
		changes = false;
		reloadInventory();
	}
	
	// Switch menus
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
			break;
		case(UserInput::K_ESC):
			// Return back
			changes = true;
			currentType = INVENTORY;
			return false;
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
			selectedItem = inv[invMenu.getCurrentChoice()];
		} else if(currentType == EXCESSIVE && (signed) inv.size() > player->getCurrAttributes().invSpace) {
			selectedItem = inv[excessiveMenu.getCurrentChoice()];
		}
	}
	
	return true;
}

void InventoryMenu::reloadInventory() {
	ChoiceVect inventoryList;
	ChoiceVect excessiveList;
	InvList& inv = player->getInventory();
	
	for(int i = 0; i < (signed) inv.size(); i++) {
		if(i < player->getCurrAttributes().invSpace)
			inventoryList.push_back(std::make_pair(inv[i]->getName(), i));
		else
			excessiveList.push_back(std::make_pair(inv[i]->getName(), i));
	}
	invMenu.setChoices(inventoryList);
	excessiveMenu.setChoices(excessiveList);
}

void InventoryMenu::swap() {
	InvList& inv = player->getInventory();
	int indexI = invMenu.getCurrentChoice();
	int indexE = excessiveMenu.getCurrentChoice();
	
	std::cerr << indexI << "<>" << indexE << std::endl;
	
	Item* tmp = inv[indexI];
	inv[indexI] = inv[indexE];
	inv[indexE] = tmp;
}
