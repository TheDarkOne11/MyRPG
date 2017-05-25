#ifndef INFO_H
#define INFO_H

#include <iostream>
#include <sstream>
#include <fstream>

#define ChoiceVect std::vector< std::pair<std::string, int> >
#define InvList std::vector<Item*>
#define DefiningPair std::pair<int, MyObject::ObjectGroup>
#define LevelMap std::vector< std::vector<MyObject*> >

/**
 * Storage class for important constants.
 */
class Info {
public:
	const static int maxEnemiesPerLevel = 15;
	const static int maxConsumableItemsPerLevel = 5;
	const static int maxUsableItemsPerLevel = 3;
	const static int initialAttributePointsCount = 5;
	const static int hpPerPoint = 5;
	const static char symbol_staticObjectHasItem = '*';
	const static int xpLevelCap = 100;
	
	// List of Consumable items IDs
	const static int ID_healthUpgrade = 0;
	
	// List of Usable items IDs
	const static int ID_fastBoots = 0;
	const static int ID_gun = 1;
		
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
	 * Method for parsing strings from save files.
	 * @param line is the string for parsing. Substring with information is removed from it.
	 * @param delim is the delimiter which separates 2 informations.
	 * @return A substring with information.
	 */
	static std::string parseString(std::string& line, std::string delim = " ");
		
};

#endif /* INFO_H */

