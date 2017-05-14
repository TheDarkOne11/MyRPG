#include "Mob.h"

Mob::Mob(int ID, char mapSymbol, int health, int speed, int attackDmg, int attackSpeed, int range)
				: Enemy(ID, mapSymbol, health, speed, attackDmg, attackSpeed, range)
{
}

Mob::Mob(const Mob* temp) : Enemy(temp)
{
}

MyObject* Mob::clone() const {
	return new Mob(this);
}