#include "Enemy.h"

Enemy::Enemy	(int ID, char mapSymbol, std::string name, Info::Attributes attr)
				: Entity(ID, mapSymbol, name, attr)
{
}

Enemy::Enemy	(const Enemy* temp) : Entity(temp)
{
}

Enemy::~Enemy() {
	clearPath();
}

Enemy::PathStep::PathStep(int y, int x, PathStep* parent) 
		: y(y), x(x), inPath(false), parent(parent)
{
}

void Enemy::AI_update(LevelMap& levelMap, Player* player, MsgBox* msgBox) {
	while(actionsLeft > 0) {
		if( canAttackPlayer(levelMap, player, y, x) ) {
			attack(player, msgBox);
			actionsLeft--;
			continue;
		} else {
			fillPath(levelMap, player);
			PathStep* curr = pathToPlayer.back();
			
			if( move(levelMap, curr->y, curr->x) ) {
				pathToPlayer.pop_back();
				delete curr;
			}
			actionsLeft--;			
		}
	}
	
	// Refresh actionsLeft
	actionsLeft = attributes.speed;
}

void Enemy::fillPath(LevelMap& levelMap, const Player* player) {	
	if( pathToPlayer.empty() ) {
		PathStep* root = new PathStep(y, x, NULL);
		findPath(levelMap, player, root);
		delete root;
		pathToPlayer.pop_back();
		return;
	} else {
		PathStep* next = pathToPlayer.front();
		
		if( distanceToPlayer(y, x, player) < distanceToPlayer(next->y, next->x, player) ) {
			clearPath();
			PathStep* root = new PathStep(y, x, NULL);
			findPath(levelMap, player, root);
			delete root;
			pathToPlayer.pop_back();
		}
	}
}

void Enemy::findPath(LevelMap& levelMap, const Player* player, PathStep* root) {
	std::set<PathStep*, PathStepCmp> s;
	std::queue<PathStep*> q;
	PathStep* curr;
	
	q.push(root);
	s.insert(root);
	while(q.size() != 0) {
		curr = q.front();
		q.pop();
		
		if( canAttackPlayer(levelMap, player, curr->y, curr->x) ) {
			break;
		}
		
		// Check curr step's adjacent positions, fill queue and set when needed
		addNewStep(levelMap, s, q, new PathStep(curr->y + 1, curr->x, curr));
		addNewStep(levelMap, s, q, new PathStep(curr->y - 1, curr->x, curr));
		addNewStep(levelMap, s, q, new PathStep(curr->y, curr->x + 1, curr));
		addNewStep(levelMap, s, q, new PathStep(curr->y, curr->x - 1, curr));
	}
	
	// Construct path list
	while(curr != NULL) {
		curr->inPath = true;
		pathToPlayer.push_back(curr);
		curr = curr->parent;
	}
	
	// Remove all unused PathSteps
	for(auto it = s.begin(); it != s.end(); it++) {
		PathStep* currStep = *it;
		
		if(!currStep->inPath) {
			delete currStep;
		}
	}
	s.clear();
	
}

void Enemy::addNewStep(LevelMap& levelMap, std::set<PathStep*, PathStepCmp>& s, 
			std::queue<PathStep*>& q, PathStep* curr) 
	{
	// Check bounds
	if(curr->y < 0 || curr->y >= (signed) levelMap.size() || curr->x < 0 
			|| curr->x >= (signed) levelMap[y].size()) {
		delete curr;
		return;
	}
	
	// Check passability
	if(!levelMap[curr->y][curr->x]->getPassable()) {
		delete curr;
		return;
	}
	
	// Check if PathStep hasn't been visited already
	auto p = s.insert(curr);
	if(p.second) {
		q.push(curr);
	} else {
		delete curr;
	}
}

bool Enemy::canAttackPlayer(LevelMap& levelMap, const Player* player, const int currY, const int currX) {	
	// If Enemy & Player are in same column/ row
	if(currY == player->getY() || currX == player->getX()) {
		// If enemy in range
		if(distanceToPlayer(currY, currX, player) <= attributes.range) {
			// If no obstacle between enemy and player
			Direction currDir;
			if(currY < player->getY()) {
				currDir = DOWN;
			} else if(currY > player->getY()) {
				currDir = UP;
			} else if(currX < player->getX()) {
				currDir = RIGHT;
			} else if(currX > player->getX()) {
				currDir = LEFT;
			}
			
			Entity* target;
			bool found = findTarget(levelMap, currDir, target, currY, currX);
			
			// If entity found and it is a player, enemy can attack
			if(found) {
				if(target->getID() == Info::ID_Player) {
					return true;
				}
			}
			
		}
	}
	
	return false;
}

void Enemy::die(LevelMap& levelMap) {
	ground->addToMap(levelMap, y, x, false);
	transferItems(ground, this);
	ground = NULL;
}

MyObject* Enemy::clone() const {
	return new Enemy(this);
}

int Enemy::distanceToPlayer(const int currY, const int currX, const Player* player) {
	double dis = std::pow(currY - player->getY(), 2) + std::pow(currX - player->getX(), 2);
	return std::ceil( std::sqrt(dis) );
}

void Enemy::clearPath() {
	for(PathStep* curr : pathToPlayer) {
		delete curr;
	}
	pathToPlayer.clear();
}
