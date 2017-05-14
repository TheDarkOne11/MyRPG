/* 
 * File:   Wall.h
 * Author: petr
 *
 * Created on May 8, 2017, 6:52 PM
 */

#ifndef WALL_H
#define WALL_H

#include "StaticObject.h"

class Wall : public StaticObject {
public:
	Wall(int ID, char mapSymbol, bool isPassable);
	Wall(const Wall* temp);
		
	virtual MyObject* clone() const override;
	
private:
	
};

#endif /* WALL_H */

