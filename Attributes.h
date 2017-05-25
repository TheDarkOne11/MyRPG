#ifndef ATTRIBUTES_H
#define ATTRIBUTES_H

#include <iostream>
#include <sstream>
#include <fstream>
#include "Info.h"

/**
 * Class names all types of attributes Entities and Items have.
 * Also provides some usefull functions for attributes manipulation.
 */
class Attributes {
public:
	int maxHP;		///< How much damage can be taken.
	int speed;		///< How many actions per turn can be done.
	int attackDmg;	///< How much damage can be inflicted in one attack.
	int range;		///< Range of attack.
	int invSpace;	///< How much items can be carried

	/**
	* Standard constructor.
	* @param health
	* @param speed
	* @param attack damage
	* @param range
	* @param inventory space
	*/
	Attributes(int h = 0, int s = 0, int ad = 0, int r = 0, int inv = 0);

	Attributes operator+(const Attributes& right) const;

	Attributes operator-(const Attributes& right) const;

	/**
	 * Set all attributes to 0.
	 */
	void clear();

	/**
	* Load attributes from a file.
	* @param file
	*/
	void load(std::ifstream& file);

	/**
	* Save attributes into a file
	* @param file
	*/
	void save(std::ofstream& file);

	/**
	* Output information about attributes.
	*/
	friend std::ostream& operator<<(std::ostream& os, const Attributes attr);
};

#endif /* ATTRIBUTES_H */

