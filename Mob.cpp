#include "Mob.h"

Mob::Mob(char mapSymbol, int health, int speed, int attackDmg, int attackSpeed)
				: Entity(mapSymbol, health, speed, attackDmg, attackSpeed)
{
}

MyObject* Mob::clone() const {
	return new Mob(mapSymbol, health, speed, attackDmg, attackSpeed);
}