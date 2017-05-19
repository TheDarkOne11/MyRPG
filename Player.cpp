#include "Player.h"

Player::Player(int ID, char mapSymbol, std::string name, Info::Attributes attr) 
			: Entity(ID, mapSymbol, name, attr), currDirection(RIGHT), doorFound(false)
{
}

Player::Player(const Player* temp) : Entity(temp), currDirection(temp->currDirection), doorFound(false)
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
	actionsMade = 0;
}

void Player::setName(std::string name) {
	this->name = name;
}

void Player::update(LevelMap& vect_levelMap, MsgBox* msgBox) {
	bool madeAction = false;
	
	switch(UserInput::getPressedKey()) {
		case(UserInput::K_UP):
			madeAction = Entity::move(vect_levelMap, y - 1, x);
			currDirection = UP;
			break;
		case(UserInput::K_DOWN):
			madeAction = Entity::move(vect_levelMap, y + 1, x);
			currDirection = DOWN;
			break;
		case(UserInput::K_LEFT):
			madeAction = Entity::move(vect_levelMap, y, x - 1);
			currDirection = LEFT;
			break;
		case(UserInput::K_RIGHT):
			madeAction = Entity::move(vect_levelMap, y, x + 1);
			currDirection = RIGHT;
			break;
		case(UserInput::K_ATTACK):
			Entity* target;
			madeAction = true;
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
	
	if(madeAction)
		actionsMade--;
}
