#ifndef PLAYERATTRIBUTES_H
#define PLAYERATTRIBUTES_H

#include "Player.h"
#include "UserInput.h"
#include "Screen.h"


/**
 * Class helps player manipulate with its attributes.
 */
class PlayerAttributes {
public:
	PlayerAttributes(Player*& player);
	
	void update();
	
	void paint();
private:
	
};

#endif /* PLAYERATTRIBUTES_H */

