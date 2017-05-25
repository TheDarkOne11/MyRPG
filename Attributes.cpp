#include "Attributes.h"

Attributes::Attributes(int h, int s, int ad, int r, int inv)
				: maxHP(h), speed(s), attackDmg(ad), range(r), invSpace(inv)
{
}

Attributes Attributes::operator+(const Attributes& right) const {
	return Attributes(maxHP + right.maxHP, speed + 
			right.speed, attackDmg + right.attackDmg, 
			range + right.range, invSpace + right.invSpace);
}

Attributes Attributes::operator-(const Attributes& right) const {
	return Attributes(maxHP - right.maxHP, speed - 
			right.speed, attackDmg - right.attackDmg, 
			range - right.range, invSpace - right.invSpace);
}

std::ostream& operator<<(std::ostream& os, const Attributes attr) {
	os << "HP: " << attr.maxHP << ", AD: " << attr.attackDmg << ", Speed: "
			<< attr.speed << ", Range: " << attr.range 
			<< ", InvSpace: " << attr.invSpace;
	
	return os;
}

void Attributes::save(std::ofstream& file) {
	file << maxHP << " " << attackDmg << " " << speed 
			<< " " << range << " " << invSpace;
}

void Attributes::load(std::ifstream& file) {
	std::string line;
	getline(file, line);
	maxHP = stoi(Info::parseString(line));
	attackDmg = stoi(Info::parseString(line));
	speed = stoi(Info::parseString(line));
	range = stoi(Info::parseString(line));
	invSpace = stoi(Info::parseString(line));
}

void Attributes::clear() {
	maxHP = 0;
	attackDmg = 0;
	range = 0;
	speed = 0;
	invSpace = 0;
}