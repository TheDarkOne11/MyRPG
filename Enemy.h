#ifndef ENEMY_H
#define ENEMY_H

#include <queue>
#include <set>
#include <algorithm>
#include <cmath>
#include <list>
#include "Entity.h"
#include "Player.h"

class Enemy : public Entity {
public:
	/**
	 * This constructor is used for setting up "template" instances of derived classes.
	 * @param ID
	 * @param mapSymbol
	 * @param name
	 * @param attr
	 */
	Enemy(int ID, char mapSymbol, std::string name, Info::Attributes attr);
	
	/**
	 * This constructor is used for cloning "templates" of derived classes.
	 * @param temp is a "template" instance of the derived class.
	 */
	Enemy(const Enemy* temp);
	
	virtual ~Enemy();
	
	void die(LevelMap& levelMap);
		
	/**
	 * Update enemy. 
	 * @param levelMap
	 * @param player
	 * @param msgBox for adding new messages.
	 */
	void AI_update(LevelMap& levelMap, Player* player, MsgBox* msgBox);
	
	MyObject* clone() const override;
	
protected:
	/**
	 * Node of pathToPlayer.
	 */
	struct PathStep {
		/** Coordinates */
		int y, x;
		/** True if this PathStep is part of the pathToPlayer */
		bool inPath;
		/** Pointer to previous PathStep. */
		PathStep* parent;
		
		PathStep(int y, int x, PathStep* parent);
	};
	
	/**
	 * Stores steps to take in order to move to and attack player.
	 */
	std::list<PathStep*> pathToPlayer;
	
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
	
	/**
	 * Check if player can be attacked from this position.
	 * Checks for distance and obstacles in the way.
	 * @param levelMap
	 * @param player
	 * @param currY is y-coord of the position we want to attack from.
	 * @param currX is x-coord of the position we want to attack from.
	 * @return true if Enemy can attack Player from this position
	 */
	bool canAttackPlayer(LevelMap& levelMap, const Player* player, const int currY, const int currX);
	
	/**
	 * Get distance to player from this position.
	 * @param currY is y-coord of the position we want to get distance to player from.
	 * @param currX is y-coord of the position we want to get distance to player from.
	 * @param player
	 * @return distance to player rounded up.
	 */
	int distanceToPlayer(const int currY, const int currX, const Player* player);
	
	/**
	 * Remove everything from pathToPlayer list.
	 */
	void clearPath();
	
private:
	/**
	 * Used as comparator for set<PathStep*>. Compares two PathSteps.
	 */
	struct PathStepCmp {
		bool operator()(const PathStep* left, const PathStep* right) {
			return (left->y < right->y) || ( (left->y == right->y) && (left->x < right->x) );
		}
	};
	
	/**
	 * Adds new PathStep to all possible PathSteps if it hasn't been visited yet.
	 * @param levelMap
	 * @param s is set of all visited PathSteps
	 * @param q is queue of all PathSteps we should visit
	 * @param curr is the current PathStep we want to add.
	 */
	void addNewStep(LevelMap& levelMap, std::set<PathStep*, PathStepCmp>& s, 
				std::queue<PathStep*>& q, PathStep* curr);
};

#endif /* ENEMY_H */

