#include "Player.h"

Player::Player(int ID, char mapSymbol, std::string name, Info::Attributes attr) 
			: Entity(ID, mapSymbol, name, attr), currDirection(RIGHT), 
			doorFound(false), attrPointsCount(Info::initialAttributePointsCount)
{
}

Player::Player(const Player* temp) : Entity(temp), 
		currDirection(temp->currDirection), doorFound(false), attrPointsCount(temp->attrPointsCount)
{
}

void Player::paint(Screen* screen, const int y, const int x) {
	mvwaddch(screen->getCurrScreen(), y, x, currDirection);
}

void Player::save(std::ofstream& file) {
	Entity::save(file);

	file << name << " " << currDirection << " " << attrPointsCount << '\n';
	
	// Save inventory indexes of equiped items
	// TODO enable
	/*for(auto it = inventory.begin(); it != inventory.end(); it++) {
		Item* curr = *it;
		if(curr->getEquiped()) {
			file << (it - inventory.begin()) << " ";
		}
	}
	file << '\n';*/
	
	file.flush();
}

void Player::load(std::ifstream& file) {
	Entity::load(file);

	std::string line;
	getline(file, line);
	
	name = Info::parseString(line);
	currDirection = (Direction) stoi(Info::parseString(line));
	attrPointsCount = stoi(Info::parseString(line));
	
	// TODO inventory
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
	actionsLeft = getCurrAttributes().speed;
}

void Player::setName(std::string name) {
	this->name = name;
}

void Player::update(LevelMap& levelMap, MsgBox* msgBox) {
	bool madeAction = false;
	
	switch(UserInput::getPressedKey()) {
		case(UserInput::K_UP):
			madeAction = Entity::move(levelMap, y - 1, x);
			currDirection = UP;
			break;
		case(UserInput::K_DOWN):
			madeAction = Entity::move(levelMap, y + 1, x);
			currDirection = DOWN;
			break;
		case(UserInput::K_LEFT):
			madeAction = Entity::move(levelMap, y, x - 1);
			currDirection = LEFT;
			break;
		case(UserInput::K_RIGHT):
			madeAction = Entity::move(levelMap, y, x + 1);
			currDirection = RIGHT;
			break;
		case(UserInput::K_ATTACK):
			Entity* target;
			madeAction = true;
			if( findTarget(levelMap, currDirection, target, y, x) ) {
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
		actionsLeft--;
}

int Player::getAttrPointsCount() {
	return attrPointsCount;
}

void Player::setAttrPointsCount(int i) {
	attrPointsCount = i;
}
