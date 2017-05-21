#include "AttributesMenu.h"

AttributesMenu::AttributesMenu(Player*& player) : attributesMenu("Player Attributes"), 
				player(player), dummy(0, 0, 0, 0)
{
	// Init choices menu
	ChoiceVect choices;
	choices.push_back( std::make_pair("<Health>", HEALTH) );
	choices.push_back( std::make_pair("<Attack damage>", ATTACK_DAMAGE) );
	choices.push_back( std::make_pair("<Speed>", SPEED) );
	choices.push_back( std::make_pair("<Range>", RANGE) );
	choices.push_back( std::make_pair("CONTINUE", CONTINUE) );
	attributesMenu.setChoices(choices);	
}

bool AttributesMenu::update() {
	AttributeMenuChoices tmp = (AttributeMenuChoices) attributesMenu.update();
	int currAttrPoints = player->getAttrPointsCount();
	
	if(tmp == CONTINUE) {
		// Player chose to return to the previous screen
		player->attributes = player->attributes + dummy;
		dummy.clear();
		return false;
	}
	
	switch(UserInput::getPressedKey()) {
		case(UserInput::K_LEFT):
			if(changeChosenAttribute(-1)) {
				currAttrPoints++;
			}
			break;
		case(UserInput::K_RIGHT):
			if(currAttrPoints <= 0) {
				break;
			}
			
			if(changeChosenAttribute(1)) {
				currAttrPoints--;
			}
			break;
	}
	player->setAttrPointsCount(currAttrPoints);
	
	return true;
}

bool AttributesMenu::changeChosenAttribute(const int change) {
	AttributeMenuChoices choice = (AttributeMenuChoices) attributesMenu.getCurrentChoice();
	int tmp;
	bool changed = false;
	
	switch(choice) {
		case(HEALTH):
			tmp = dummy.maxHP + change * Info::hpPerPoint;
			if(tmp >= 0) {
				dummy.maxHP = tmp;
				changed = true;
			}
			break;
		case(ATTACK_DAMAGE):
			tmp = dummy.attackDmg + change;
			if(tmp >= 0) {
				dummy.attackDmg = tmp;
				changed = true;
			}
			break;
		case(SPEED):
			tmp = dummy.speed + change;
			if(tmp >= 0) {
				dummy.speed = tmp;
				changed = true;
			}
			break;
		case(RANGE):
			tmp = dummy.range + change;
			if(tmp >= 0) {
				dummy.range = tmp;
				changed = true;
			}
			break;
		case(CONTINUE):
			break;
	}
	
	return changed;
}

void AttributesMenu::paint(Screen* screen) {		
	std::stringstream ss, ss2;
	
	// Paint attributes menu
	screen->setCurrScreen(screen->ATTRIBUTES);
	attributesMenu.paint(screen);
	screen->sRefresh();
	
	// Paint info menu
	screen->setCurrScreen(screen->INFO);
	ss << "After CONTINUE,  " << player->getName() << " will have these stats: " << (player->attributes + dummy);
	ss2 << "You currently invested in these stats: " << dummy;
	
	mvwprintw(screen->getCurrScreen(), 0, 0, "Change attributes using LEFT/ RIGHT arrow keys.");
	mvwprintw(screen->getCurrScreen(), 1, 0, ss.str().c_str());
	mvwprintw(screen->getCurrScreen(), 2, 0, ss2.str().c_str());
	mvwprintw(screen->getCurrScreen(), 3, 0, "You have %d points left.", player->getAttrPointsCount());
}
