#include "Info.h"

const std::string Info::pathDirMaps = "./res/maps";
const std::string Info::pathDirSaves = "./res/saves";
const std::string Info::pathNamesMaps = pathDirMaps + "/" + "fileNames";
const std::string Info::pathNamesSaves = pathDirSaves + "/" + "fileNames";

Info::Attributes::Attributes(int h, int s, int ad, int r, int inv)
				: maxHP(h), speed(s), attackDmg(ad), range(r), invSpace(inv)
{
}

Info::Attributes Info::Attributes::operator+(const Attributes& right) const {
	return Attributes(maxHP + right.maxHP, speed + 
			right.speed, attackDmg + right.attackDmg, 
			range + right.range, invSpace + right.invSpace);
}

Info::Attributes Info::Attributes::operator-(const Attributes& right) const {
	return Attributes(maxHP - right.maxHP, speed - 
			right.speed, attackDmg - right.attackDmg, 
			range - right.range, invSpace - right.invSpace);
}

std::ostream& operator<<(std::ostream& os, const Info::Attributes attr) {
	os << attr.maxHP << " " << attr.attackDmg << " " << attr.speed 
			<< " " << attr.range << " " << attr.invSpace;
	
	return os;
}

std::string Info::Attributes::getInfo() const {
	std::stringstream os;
	os << "HP: " << maxHP << ", AD: " << attackDmg << ", Speed: "
			<< speed << ", Range: " << range 
			<< ", InvSpace: " << invSpace;
	
	return os.str();
}

void Info::Attributes::clear() {
	maxHP = 0;
	attackDmg = 0;
	range = 0;
	speed = 0;
	invSpace = 0;
}
