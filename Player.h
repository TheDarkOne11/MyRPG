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
	Player(int ID, char mapSymbol, std::string name, Info::Attributes attr);
	
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
	void save(std::ofstream& file) override;
	
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
	bool getDoorFound();
	
	int getAttrPointsCount();
	
	void setAttrPointsCount(int i);
	
	void setName(std::string name);
	
	int getLevelsCleared();
	
	int getEnemiesKilled();
	
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
	Direction currDirection;
	bool doorFound;
	
	/**
	 * Number of currently owned attribute points for upgrading player's attributes.
	 */
	int attrPointsCount;
	int currXP;
	int levelsCleared;
	int enemiesKilled;
};

#endif /* PLAYER_H */

