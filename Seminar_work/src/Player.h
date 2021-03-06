#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"
#include "UserInput.h"

class Player : public Entity {
public:
	/**
	 * This constructor is used for setting up "template" instances of Player class.
	 * @param ID
	 * @param mapSymbol
	 * @param name
	 * @param attr
	 */
	Player(int ID, char mapSymbol, std::string name, Attributes attr);
	
	/**
	 This constructor is used for cloning "templates" of Player class.
	 * @param temp is a "template" instance of the derived class.
	 */
	Player(const Player* temp);

	/**
	 * Overriden for painting player direction instead of mapSymbol.
	 * @param screen
	 * @param y
	 * @param x
	 */
	virtual void paint(Screen* screen, const int y, const int x) override;
	
	/**
	 * Chech for player movement, attack etc.
	 * @param levelMap
	 * @param msgBox
	 */
	void update(LevelMap& levelMap, MsgBox* msgBox);
	
	/**
	 * Save Player info into a file.
	 * @param file
	 */
	void save(std::ofstream& file) const override;
	
	/**
	 * Load Player info from a file.
	 * @param file
	 */
	void load(std::ifstream& file) override;
			
	/**
	 * Checks ground for items and for doors to next level.
	 */
	void checkGround() override;
	
	/**
	 * Check if player found door to next level.
	 * @return True if player found the door.
	 */
	bool getDoorFound() const;
	
	int getAttrPointsCount();
	
	void setAttrPointsCount(const int i);
	
	void setName(std::string name);
	
	int getLevelsCleared() const;
	
	int getEnemiesKilled() const;
	
	/**
	 * Player found the door and proccedes to the next level.
	 * This method updates some of his attributes.
	 */
	void prepareToNextLevel();
	
	/**
	 * Returns a clone Player instance of the current MyObject.
	 * @return Clone of Player instance of MyObject.
	 */
	virtual MyObject* clone() const override;
	
private:
	Direction currDirection;///< Direction player currently faces.
	bool doorFound;			///< True if player found door to the next level.
	int attrPointsCount;	///< Number of currently owned attribute points for upgrading player's attributes.
	int currXP;				///< Currently earned xp.
	int levelsCleared;		///< Number of cleared levels.
	int enemiesKilled;		///< Number of killed enemies.
};

#endif /* PLAYER_H */

