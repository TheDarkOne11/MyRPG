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
	Wall(char mapSymbol, bool isPassable);
	Wall(const Wall* temp);
	
	void addToMap(std::vector<std::vector<MyObject*> >& vect_gameMap, int y, int x) override;
	
	virtual MyObject* clone() const override;
	
private:
	
};

#endif /* WALL_H */

