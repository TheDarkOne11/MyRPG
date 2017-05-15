#ifndef INFO_H
#define INFO_H

#include <ncurses.h>
#include <fstream>
#include <vector>

/**
 * Storage class for important constants.
 */
class Info {
public:
	// TODO Put them in config file? Maybe update them with player level?
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
	
	struct Attributes {
		int health, speed;
		int attackDmg, attackSpeed, range;
		
		Attributes(int h, int s, int ad, int as, int r)
				: health(h), speed(s), attackDmg(ad), attackSpeed(as), range(r)
		{
		}
		
		Attributes operator+(const Attributes& right) {
			return Attributes(health + right.health, speed + 
					right.speed, attackDmg + right.attackDmg, 
					attackSpeed + right.attackSpeed, range + right.range);
		}
		
		Attributes operator-(const Attributes& right) {
			return Attributes(health - right.health, speed - 
					right.speed, attackDmg - right.attackDmg, 
					attackSpeed - right.attackSpeed, range - right.range);
		}
	};
	
private:	
	std::vector<std::string> fileNamesMaps;
	std::vector<std::string> fileNamesSaves;
};

#endif /* INFO_H */

