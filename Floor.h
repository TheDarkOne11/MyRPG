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
	Floor(char mapSymbol);
	
	MyObject* clone() const override;
	
private:

};

#endif /* FLOOR_H */

