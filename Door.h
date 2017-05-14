#ifndef DOOR_H
#define DOOR_H

#include "StaticObject.h"


class Door : public StaticObject {
public:
	/**
	 * This constructor is used for setting up "template" instances of derived classes.
	 * @param mapSymbol what the object looks like in the game
	 */
	Door(int ID, char mapSymbol, bool isPassable);
	
	/**
	 * This constructor is used for cloning "templates" of derived classes.
	 * @param temp is a "template" instance of the derived class.
	 */
	Door(const StaticObject* temp);
	
	MyObject* clone() const override;

private:

};

#endif /* DOOR_H */

