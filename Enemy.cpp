#include "Enemy.h"

Enemy::Enemy	(int ID, char mapSymbol, std::string name, Info::Attributes attr)
				: Entity(ID, mapSymbol, name, attr)
{
}

Enemy::Enemy	(const Enemy* temp) : Entity(temp)
{
}

Enemy::~Enemy() {
	while(!pathToPlayer.empty()) {
		PathStep* curr = pathToPlayer.top();
		delete curr;
		pathToPlayer.pop();
	}
}

Enemy::PathStep::PathStep(int y, int x, PathStep* parent) 
		: y(y), x(x), inPath(false), parent(parent)
{
}

void Enemy::AI_update(LevelMap& levelMap, const Player* player, MsgBox* msgBox) {
	fillPath(levelMap, player);
	
	PathStep* curr = pathToPlayer.top();
	pathToPlayer.pop();
	move(levelMap, curr->y, curr->x);
}

void Enemy::fillPath(LevelMap& levelMap, const Player* player) {	
	// TODO remove
	std::stack<PathStep*> empty;
	std::swap(pathToPlayer, empty);
	
	PathStep* root = new PathStep(y, x, NULL);
	findPath(levelMap, player, root);
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
		
		if(curr->y == player->getY() || curr->x == player->getX()) {
			if(getDistanceToPlayer(curr, player) <= attributes.range) {
				break;
			}
		}
		
		// Check curr step's adjacent positions, fill queue and set when needed
		addNewStep(levelMap, s, q, new PathStep(curr->y + 1, curr->x, curr));
		addNewStep(levelMap, s, q, new PathStep(curr->y - 1, curr->x, curr));
		addNewStep(levelMap, s, q, new PathStep(curr->y, curr->x + 1, curr));
		addNewStep(levelMap, s, q, new PathStep(curr->y, curr->x - 1, curr));
	}
	
	// Construct path list
	while(curr != root) {
		curr->inPath = true;
		pathToPlayer.push(curr);
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
	if(curr->y < 0 || curr->y >= levelMap.size() || curr->x < 0 || curr->x >= levelMap[y].size()) {
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

int Enemy::getDistanceToPlayer(PathStep* curr, const Player* player) {
	double dis = std::pow(curr->y - player->getY(), 2) + std::pow(curr->x - player->getX(), 2);
	
	return std::ceil( std::sqrt( dis ) );
}

void Enemy::die(LevelMap& levelMap) {
	ground->addToMap(levelMap, y, x, false);
	ground = NULL;
}

MyObject* Enemy::clone() const {
	return new Enemy(this);
}