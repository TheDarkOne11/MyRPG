#ifndef INFO_H
#define INFO_H

#include <iostream>

#define ChoiceVect std::vector< std::pair<std::string, int> >
#define DefiningPair std::pair<int, MyObject::ObjectGroup>
#define LevelMap std::vector< std::vector<MyObject*> >

/**
 * Storage class for important constants.
 */
class Info {
public:
	const static int maxEnemiesPerLevel = 15;
	const static int maxItemsPerLevel = 5;
		
	// List of StaticObject IDs
	const static int ID_Door = 0;
	const static int ID_Floor = 1;
	const static int ID_Wall = 2;
	
	// List of Entity IDs
	const static int ID_Player = 0;
	const static int ID_Mob = 1;
	const static int ID_Mob2 = 2;
	
	// Constants for working with files
	const static std::string pathDirMaps;
	const static std::string pathNamesMaps;
	const static std::string pathDirSaves;
	const static std::string pathNamesSaves;
	
	/**
	 * Struct of all types of attributes every Entity and Item can have.
	 */
	struct Attributes {
		int health, speed;
		int attackDmg, range;
		
		Attributes(int h, int s, int ad, int r)
				: health(h), speed(s), attackDmg(ad), range(r)
		{
		}
		
		Attributes operator+(const Attributes& right) {
			return Attributes(health + right.health, speed + 
					right.speed, attackDmg + right.attackDmg, 
					range + right.range);
		}
		
		Attributes operator-(const Attributes& right) {
			return Attributes(health - right.health, speed - 
					right.speed, attackDmg - right.attackDmg, 
					range - right.range);
		}
	};
		
};

#endif /* INFO_H */

