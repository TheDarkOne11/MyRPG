#ifndef ENEMY_H
#define ENEMY_H

#include <queue>
#include <set>
#include <algorithm>
#include <cmath>
#include <stack>
#include "Entity.h"
#include "Player.h"

class Enemy : public Entity {
public:
	/**
	 * This constructor is used for setting up "template" instances of derived classes.
	 * @param ID
	 * @param mapSymbol what the entity looks like in the game
	 * @param health
	 * @param speed
	 * @param attackDmg
	 * @param attackSpeed
	 */
	Enemy	(int ID, char mapSymbol, std::string name, Info::Attributes attr);
	
	/**
	 This constructor is used for cloning "templates" of derived classes.
	 * @param temp is a "template" instance of the derived class.
	 */
	Enemy	(const Enemy* temp);
	
	~Enemy();
	
	void die(LevelMap& levelMap);
		
	void AI_update(LevelMap& levelMap, const Player* player, MsgBox* msgBox);
	
	MyObject* clone() const override;
	
protected:
	struct PathStep {
		int y, x;
		bool inPath;
		PathStep* parent;
		
		PathStep(int y, int x, PathStep* parent);
	};
	
	/**
	 * Stores steps to take in order to move to and attack player.
	 */
	std::stack<PathStep*> pathToPlayer;
	
	/**
	 * Fills path which Enemy has to take in order to attack player.
	 * If pathToPlayer list already exists, it tries to use it.
	 * @param levelMap
	 * @param player
	 */
	void fillPath(LevelMap& levelMap, const Player* player);
	
	/**
	 * Finds path which Enemy has to take in order to attack player.
	 * @param levelMap
	 * @param player
	 * @param root is the starting position for findPath
	 */
	void findPath(LevelMap& levelMap, const Player* player, PathStep* root);
	
	int getDistanceToPlayer(PathStep* curr, const Player* player);
	
private:
	/**
	 * Used as comparator for set<PathStep*>. Compares two PathSteps.
	 */
	struct PathStepCmp {
		bool operator()(const PathStep* left, const PathStep* right) {
			return (left->y < right->y) || ( (left->y == right->y) && (left->x < right->x) );
		}
	};
	
	void addNewStep(LevelMap& levelMap, std::set<PathStep*, PathStepCmp>& s, 
				std::queue<PathStep*>& q, PathStep* curr);
};

#endif /* ENEMY_H */

