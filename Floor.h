#ifndef FLOOR_H
#define FLOOR_H

#include "StaticObject.h"

class Floor : public StaticObject {
public:
	Floor(int ID, char mapSymbol, bool isPassable);
	Floor(const Floor* temp);
	
	MyObject* clone() const override;
};

#endif /* FLOOR_H */

