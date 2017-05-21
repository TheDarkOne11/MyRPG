#ifndef INFO_H
#define INFO_H

#include <iostream>

#define ChoiceVect std::vector< std::pair<std::string, int> >
#define InvList std::list<Item*>
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
	
	// List of Consumable items IDs
	const static int ID_healthPotion = 0;
	
	// List of Usable items IDs
	const static int ID_fastBoots = 0;
	const static int ID_bag = 1;
		
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
		
		Attributes operator+(const Attributes& right);
		
		Attributes operator-(const Attributes& right);
		
		void clear();
		
		/**
		 * Output all Attributes information.
		 */
		friend std::ostream& operator<<(std::ostream& os, const Attributes attr);
	};
		
};

#endif /* INFO_H */

