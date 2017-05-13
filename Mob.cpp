#include "Mob.h"

Mob::Mob(char mapSymbol, int health, int speed, int attackDmg, int attackSpeed)
				: Entity(mapSymbol, health, speed, attackDmg, attackSpeed)
{
}

Mob::Mob(const Mob* temp) : Entity(temp)
{
}

MyObject* Mob::clone() const {
	return new Mob(this);
}