#ifndef PLAYERATTRIBUTES_H
#define PLAYERATTRIBUTES_H

#include <sstream>
#include "Player.h"
#include "UserInput.h"
#include "Screen.h"
#include "Menu.h"
#include "Attributes.h"

/**
 * Class handles a special menu used for manipulating player attributes.
 */
class AttributesMenu {
public:
	enum AttributeMenuChoices {
		HEALTH,			///< Change health
		ATTACK_DAMAGE,	///< Change attack damage
		SPEED,			///< Change speed
		RANGE,			///< Change attack range
		INV_SPACE		///< Change inventory space
	};
	
	AttributesMenu();
	
	/**
	 * Iteration throught attributes menu.
	 * @return False if player wants out of Attributes menu.
	 */
	bool update();
	
	/**
	 * Paint attributes menu.
	 * @param screen
	 */
	void paint(Screen* screen);
	
	void setPlayer(Player* player);
private:
	Menu attributesMenu;
	Player* player;
	Attributes dummy; ///< Dummy atributes, used for applying changes.
	
	/**
	 * Change attributes according to the player choice.
	 * @param change says how much the attribute has to change.
	 * @return True if any attribute value was successfuly changed.
	 */
	bool changeChosenAttribute(const int change);
};

#endif /* PLAYERATTRIBUTES_H */

