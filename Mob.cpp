#include "Mob.h"

Mob::Mob(int ID, char mapSymbol, std::string name, int health, int speed, 
		int attackDmg, int attackSpeed, int range)
				: Enemy(ID, mapSymbol, name, health, speed, attackDmg, attackSpeed, range)
{
}

Mob::Mob(const Mob* temp) : Enemy(temp)
{
}

MyObject* Mob::clone() const {
	return new Mob(this);
}