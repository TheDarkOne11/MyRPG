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
	while( std::getline(file, s) ) {
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
	int ranNum;
		
	// Add player to random position
	curr = getPossiblePos(possiblePositions, ranPos);
	player->addToMap(levelMap, curr->getY(), curr->getX(), false);
	
	// Add door to random position
	MyObject* door = Handler::getMyObject(MyObject::STATIC, Info::ID_Door);
	ranPos = rand() % possiblePositions.size();
	curr = getPossiblePos(possiblePositions, ranPos);
	door->addToMap(levelMap, curr->getY(), curr->getX(), true);
	
	// Add random number of random items
	ranNum = rand() % Info::maxConsumableItemsPerLevel + 1;
	addRandomItems(possiblePositions, ranNum, Item::CONSUMABLE);
	ranNum = rand() % Info::maxUsableItemsPerLevel + 1;
	addRandomItems(possiblePositions, ranNum, Item::USEABLE);
	
	// Add random number of random enemies
	ranNum = rand() % Info::maxEnemiesPerLevel + 1;
	for(int i = 0; i < ranNum || possiblePositions.size() < 0; i++) {
		// Get random enemy
		Enemy* enemy = dynamic_cast<Enemy*> (Handler::getMyObject(MyObject::ENTITY));
		ranPos = rand() % possiblePositions.size();
		curr = getPossiblePos(possiblePositions, ranPos);
		
		enemies.push_back(enemy);
		enemy->addToMap(levelMap, curr->getY(), curr->getX(), false);
	}
}

MyObject* FileHandler::getPossiblePos(InnerVect& possiblePositions, int index) {
	MyObject* curr = possiblePositions[index];
	possiblePositions.erase( possiblePositions.begin() + index );
	return curr;
}

void FileHandler::addRandomItems(const InnerVect& possiblePositions, 
			const int count, const Item::ItemType type) {
	int ranPos;
	int currCount = 0;
	for(int i = 0; i < count || possiblePositions.size() < 0; i += currCount) {
		ranPos = rand() % possiblePositions.size();
		MyObject* curr = possiblePositions.at(ranPos);
		
		// How many items in current position
		currCount = rand() % (count - i) + 1;
		
		// Add currCount of items to the current MyObject
		for(int f = 0; f < currCount; f++) {
			Item* item = Handler::getItem(type);
			InvList& inv = curr->getInventory();
			inv.push_back( item );
		}
	}
}

void FileHandler::saveGame(const LevelMap& levelMap, const std::string playerName) {
	std::stringstream ss;
	
	// Get unique name using time
	time_t t = time(0);
    struct tm * now = localtime( & t );
	ss << now->tm_hour << now->tm_min << now->tm_gmtoff << "_"
			<< now->tm_mday << now->tm_mon + 1 << now->tm_year + 1900;
	
	std::string fileName =  ss.str() + "_" + playerName;	
	std::ofstream file( Info::pathDirSaves + "/" + fileName );
	
	// Save whole levelMap into the file
	for(auto it = levelMap.begin(); it != levelMap.end(); it++) {
		for(MyObject* curr : *it) {
			curr->save(file);
		}
	}
	
	// Save new filename inside filenames file
	// TODO Sort them, newest on top
	std::ofstream saveFileNames(Info::pathNamesSaves, std::ofstream::app);
	saveFileNames << fileName << '\n';
	
	
	saveFileNames.flush();
	saveFileNames.close();
	file.flush();
	file.close();
}

void FileHandler::loadGame(std::string fileName, LevelMap& levelMap, EnemyVect& enemies, Player*& player) {
	std::ifstream file(Info::pathDirSaves + "/" + fileName);
	std::string line;
	int lastY = 0;
	InnerVect row;
	
	if(!file.is_open()) {
		throw "File " + fileName + " didn't open.";
	}
		
	/*
	 * 1/ Read MyObject's ID and group.
	 * 2/ Create this MyObject using Handler.
	 * 3/ Use load() method of this MyObject.
	 * 4/ Repeat until eof.
	 */
	while(std::getline(file, line)) {
		int ID = stoi(Info::parseString(line));
		MyObject::ObjectGroup group = (MyObject::ObjectGroup) stoi(Info::parseString(line));
		MyObject* currObject = Handler::getMyObject(group, ID);
		currObject->load(file);
				
		if(group == MyObject::ENTITY) {
			if(ID == Info::ID_Player) {
				player = dynamic_cast<Player*>(currObject);
			} else {
				enemies.push_back(dynamic_cast<Enemy*>(currObject));
			}
		}
		
		if(lastY != currObject->getY()) {
			lastY++;
			levelMap.push_back(row);
			row.clear();
		}
		
		row.push_back(currObject);
	}
	
	levelMap.push_back(row);
	file.close();
}
