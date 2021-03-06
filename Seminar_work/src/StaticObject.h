#ifndef STATIC_OBJECT_H
#define STATIC_OBJECT_H

#include "MyObject.h"

/**
 * Super class for static objects (walls, floors, doors...)
 */
class StaticObject : public MyObject {
public:
	/**
	 * This constructor is used for setting up "template" instances of derived classes.
	 * @param ID
	 * @param mapSymbol
	 * @param isPassable
	 * @param name
	 */
	StaticObject(int ID, char mapSymbol, bool isPassable, std::string name);
	
	/**
	 * This constructor is used for cloning "templates" of derived classes.
	 * @param temp is a "template" instance of the derived class.
	 */
	StaticObject(const StaticObject* temp);
	
	/**
	 * Override: When StaticObject has an item, it's painted differently.
	 * @param screen
	 * @param y
	 * @param x
	 */
	void paint(Screen* screen, const int y, const int x) override;
	
	/**
	 * Returns a clone derived instance of the current MyObject.
	 * @return Clone of more derived instance of MyObject.
	 */
	MyObject* clone() const override;
};

#endif /* STATIC_OBJECT_H */

