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
		HEALTH,			///< Change health
		ATTACK_DAMAGE,	///< Change attack damage
		SPEED,			///< Change speed
		RANGE,
		CONTINUE		///< Leave AttributesMenu
	};
	
	
	AttributesMenu(Player*& player);
	
	bool update();
	
	void paint(Screen* screen);
private:
	Menu attributesMenu;
	Player* player;
	
	/**
	 * Dummy atributes, used for applying changes.
	 */
	Info::Attributes dummy;
	
	/**
	 * Change attributes according to the player choice.
	 * @param change says how much the attribute has to change.
	 * @return true if any attribute value was successfuly changed.
	 */
	bool changeChosenAttribute(const int change);
};

#endif /* PLAYERATTRIBUTES_H */

