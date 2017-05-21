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
 * Handles saving/ loading levels.
 */
class FileHandler {
public:
	enum FileType {
		SAVE,
		MAP
	};
	
	FileHandler();
	
	/**
	 * Loads random map layout from maps directory.
	 * @param levelMap
	 * @param enemies is vector of all enemies in the map.
	 * @param player
	 */
	void loadLevel(LevelMap& levelMap, EnemyVect& enemies, Player*& player);
	
	/**
	 * Saves the game.
	 */
	void saveGame(LevelMap& levelMap);
	
	/**
	 * Loads saved game.
	 */
	void loadGame(LevelMap& levelMap);
	
private:
	std::vector<std::string> fileNamesSaves;
	std::vector<std::string> fileNamesMaps;
	
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
	
	MyObject* getPossiblePos( InnerVect& possiblePositions, int index );
	
	void addRandomItems(const InnerVect& possiblePositions, 
			const int count, const Item::ItemType type);
};

#endif /* FILEHANDLER_H */

