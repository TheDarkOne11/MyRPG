#ifndef STATIC_OBJECT_H
#define STATIC_OBJECT_H

#include "MyObject.h"

/**
 * Super class for static objects (walls, chests, doors...)
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
	
	MyObject* clone() const override;
};

#endif /* STATIC_OBJECT_H */

