#include "Player.h"

Player::Player(int ID, char mapSymbol, std::string name, int health, 
		int speed, int attackDmg, int attackSpeed, int range) 
			: Entity(ID, mapSymbol, name, health, speed, attackDmg, attackSpeed, range), 
			doorFound(false)
{
}

Player::Player(const Player* temp) : Entity(temp), currDirection(RIGHT), doorFound(false)
{
}

void Player::paint(Screen* screen, const int y, const int x) {
	mvwaddch(screen->getCurrScreen(), y, x, currDirection);
}

MyObject* Player::clone() const {
	return new Player(this);
}

void Player::checkGround() {
	Entity::checkGround();
	
	if(ground->getID() == Info::ID_Door) {
		doorFound = true;
	}
}

bool Player::getDoorFound() {
	return doorFound;
}

void Player::prepareToNextLevel() {
	doorFound = false;
	delete ground;
	ground = NULL;
}

void Player::setName(std::string name) {
	this->name = name;
}

void Player::update(LevelMap& vect_levelMap, MsgBox* msgBox) {
	switch(UserInput::getPressedKey()) {
		case(UserInput::K_UP):
			Entity::move(vect_levelMap, y - 1, x);
			currDirection = UP;
			break;
		case(UserInput::K_DOWN):
			Entity::move(vect_levelMap, y + 1, x);
			currDirection = DOWN;
			break;
		case(UserInput::K_LEFT):
			Entity::move(vect_levelMap, y, x - 1);
			currDirection = LEFT;
			break;
		case(UserInput::K_RIGHT):
			Entity::move(vect_levelMap, y, x + 1);
			currDirection = RIGHT;
			break;
		case(UserInput::K_ATTACK):
			Entity* target;
			if( Entity::findTarget(vect_levelMap, currDirection, target) ) {
				// Target found
				target->isAttacked(this, msgBox);
			} else {
				// Target not found
				msgBox->addMsg("Player missed.");
			}
			break;
		default:
			return;
			break;
	}
	
	actionsMade--;
}
