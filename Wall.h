#ifndef WALL_H
#define WALL_H

#include "StaticObject.h"

class Wall : public StaticObject {
public:
	Wall(int ID, char mapSymbol, bool isPassable, std::string name);
	Wall(const Wall* temp);
		
	virtual MyObject* clone() const override;
	
private:
	
};

#endif /* WALL_H */

