#include "Info.h"

const std::string Info::pathDirMaps = "./res/maps";
const std::string Info::pathDirSaves = "./res/saves";
const std::string Info::pathNamesMaps = pathDirMaps + "/" + "fileNames";
const std::string Info::pathNamesSaves = pathDirSaves + "/" + "fileNames";

Info::Attributes::Attributes(int h, int s, int ad, int r)
				: health(h), speed(s), attackDmg(ad), range(r)
{
}

Info::Attributes Info::Attributes::operator+(const Attributes& right) {
	return Attributes(health + right.health, speed + 
			right.speed, attackDmg + right.attackDmg, 
			range + right.range);
}

Info::Attributes Info::Attributes::operator-(const Attributes& right) {
	return Attributes(health - right.health, speed - 
			right.speed, attackDmg - right.attackDmg, 
			range - right.range);
}

std::ostream& operator<<(std::ostream& os, const Info::Attributes attr) {
	os << "HP: " << attr.health << ", AD: " << attr.attackDmg << ", Speed: "
			<< attr.speed << ", Range: " << attr.range;
	
	return os;
}

void Info::Attributes::clear() {
	health = 0;
	attackDmg = 0;
	range = 0;
	speed = 0;
}
