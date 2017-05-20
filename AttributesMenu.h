#ifndef PLAYERATTRIBUTES_H
#define PLAYERATTRIBUTES_H

#include <sstream>
#include "Player.h"
#include "UserInput.h"
#include "Screen.h"
#include "Menu.h"


/**
 * Class handles a special menu used for manipulating player attributes.
 */
class AttributesMenu {
public:
	enum AttributeMenuChoices {
		HEALTH,
		ATTACK_DAMAGE,
		SPEED,
		CONTINUE
	};
	
	
	AttributesMenu(Player*& player);
	
	bool update();
	
	void paint(Screen* screen);
private:
	Menu attributesMenu;
	Player* player;
	Info::Attributes dummy;
	
	bool changeChosenAttribute(const int change);
};

#endif /* PLAYERATTRIBUTES_H */

