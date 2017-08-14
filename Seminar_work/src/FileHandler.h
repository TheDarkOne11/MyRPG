#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <vector>
#include <iostream>
#include <fstream>
#include <time.h>
#include <stdlib.h>
#include "Info.h"
#include "MyObject.h"
#include "Handler.h"

#define InnerVect std::vector<MyObject*>
#define EnemyVect std::vector<Enemy*>

/**
 * Handles saving/ loading levels in files.
 */
class FileHandler {
public:	
	FileHandler();
	
	/**
	 * Loads random map layout from maps directory.
	 * @param levelMap
	 * @param enemies is vector of all enemies in the map.
	 * @param player
	 */
	void loadLevel(LevelMap& levelMap, EnemyVect& enemies, Player*& player);
	
	/**
	 * Saves the currently played game.
	 * @param levelMap
	 * @param playerName is the name of the player.
	 */
	void saveGame(const LevelMap& levelMap, const std::string playerName);
	
	/**
	 * Loads chosen game.
	 * @param fileName is the fileName of the save file that should be loaded.
	 * @param levelMap
	 * @param enemies is the vector of all enemies in the map.
	 * @param player
	 */
	void loadGame(std::string fileName, LevelMap& levelMap, EnemyVect& enemies, Player*& player);
	
private:
	std::vector<std::string> fileNamesSaves;	///< File names of all available save files
	std::vector<std::string> fileNamesMaps;		///< File names of all available map files
	
	/**
	 * Load file names from all files
	 */
	void loadFileNames();
	
	/**
	 * Load file names from 1 file
	 * @param path is path to file
	 * @param fileNames is the vector data is stored to.
	 */
	void loadFileNames(std::string path, std::vector<std::string>& fileNames);
	
	/**
	 * Randomly adds other MyObjects into the map.
	 * @param levelMap
	 * @param enemies is vector of enemies.
	 * @param player
	 * @param possiblePositions are positions where MyObjects can spawn.
	 */
	void addRandomObjects(LevelMap& levelMap, EnemyVect& enemies, 
				Player*& player, InnerVect& possiblePositions);
	
	/**
	 * Gets a MyObject pointer and erases it from possiblePositions.
	 * @param possiblePositions is a vector of all positions available for random spawning.
	 * @param index is the index to get MyObject pointer from.
	 * @return The MyObject pointer at the index.
	 */
	MyObject* getPossiblePos( InnerVect& possiblePositions, int index );
	
	/**
	 * Adds random Items randomly into the map.
	 * @param possiblePositions
	 * @param count is a number of items to be added.
	 * @param type is the type of items to be added.
	 */
	void addRandomItems(const InnerVect& possiblePositions, 
			const int count, const Item::ItemType type);
};

#endif /* FILEHANDLER_H */

