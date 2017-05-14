/* 
 * File:   Floor.h
 * Author: petr
 *
 * Created on May 10, 2017, 10:40 PM
 */

#ifndef FLOOR_H
#define FLOOR_H

#include "StaticObject.h"

class Floor : public StaticObject {
public:
	Floor(char mapSymbol, bool isPassable);
	Floor(const Floor* temp);
	
	MyObject* clone() const override;
	
	void addToMap(std::vector<std::vector<MyObject*> >& vect_levelMap, int y, int x) override;

	
private:

};

#endif /* FLOOR_H */

