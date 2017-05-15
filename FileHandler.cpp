#include "FileHandler.h"

FileHandler::FileHandler() {
	srand(time(NULL));
	loadFileNames();
}

void FileHandler::loadFileNames() {
	loadFileNames(Info::pathNamesMaps, fileNamesMaps);
	loadFileNames(Info::pathNamesSaves, fileNamesSaves);
}

void FileHandler::loadFileNames(std::string path, std::vector<std::string>& fileNames) {
	std::ifstream file(path, std::ios::in);
	std::string s;
	
	if(!file.is_open()) 
		throw "FileHandler: Names file doesn't exist: " + path;
	
	// Read until EOF
	while( getline(file, s) ) {
		fileNames.push_back(s);
	}
	
	file.close();
}

void FileHandler::loadLevel(LevelMap& levelMap, EnemyVect& enemies, Player*& player) {
	// Get random level
	int ran = rand() % fileNamesMaps.size();
	std::string path = Info::pathDirMaps + "/" + fileNamesMaps[ran];
	
	std::ifstream file(path, std::ios::in);
	std::string s;
	
	if(!file.is_open())
		throw "FileHandler: Level layout doesn't exist: " + path;
	
	// Create game map
	InnerVect possiblePositions;	// Used for random spawning
	int x = 0;
	int y = 0;
	while( getline(file, s) ) {
		InnerVect row;
		
		for(char c : s) {
			MyObject* curr = Handler::getMyObject(c);
			curr->setCoordinates(y, x);
			row.push_back(curr);
			x++;
			
			// If Entity can go to this position, it can also spawn on it
			if(curr->getPassable()) {
				possiblePositions.push_back(curr);
			}
		}
		
		levelMap.push_back(row);
		y++;
		x = 0;
	}
	
	file.close();
	
	addRandomObjects(levelMap, enemies, player, possiblePositions);
}

void FileHandler::addRandomObjects(LevelMap& levelMap, EnemyVect& enemies, Player*& player, 
		InnerVect& possiblePositions) {
	MyObject* curr;
	int ranPos = rand() % possiblePositions.size();
	int ranNum = rand() % Info::maxEnemiesPerLevel + 1;
		
	// Add player to random position
	curr = getPossiblePos(possiblePositions, ranPos);
	player->addToMap(levelMap, curr->getY(), curr->getX(), false);
	
	// Add door to random position
	MyObject* door = Handler::getMyObject(MyObject::STATIC, Info::ID_Door);
	ranPos = rand() % possiblePositions.size();
	curr = getPossiblePos(possiblePositions, ranPos);
	door->addToMap(levelMap, curr->getY(), curr->getX(), true);
	
	// Add random number of random enemies	
	//std::cerr << "Num of Enemies added: " << ranNum << std::endl;
	for(int i = 0; i < ranNum || possiblePositions.size() < 0; i++) {
		// Get random enemy
		Enemy* enemy = dynamic_cast<Enemy*> (Handler::getMyObject(MyObject::ENTITY));
		ranPos = rand() % possiblePositions.size();
		curr = getPossiblePos(possiblePositions, ranPos);
		
		enemies.push_back(enemy);
		enemy->addToMap(levelMap, curr->getY(), curr->getX(), false);
		//std::cerr << "Enemy: " << enemy->getID() << "/ " << enemy->getMapSymbol() << std::endl;
	}
}

MyObject* FileHandler::getPossiblePos(InnerVect& possiblePositions, int index) {
	MyObject* curr = possiblePositions[index];
	possiblePositions.erase( possiblePositions.begin() + index );
	return curr;
}
