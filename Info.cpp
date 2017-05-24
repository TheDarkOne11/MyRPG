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
	os << "HP: " << attr.maxHP << ", AD: " << attr.attackDmg << ", Speed: "
			<< attr.speed << ", Range: " << attr.range 
			<< ", InvSpace: " << attr.invSpace;
	
	return os;
}

void Info::Attributes::save(std::ofstream& file) {
	file << maxHP << " " << attackDmg << " " << speed 
			<< " " << range << " " << invSpace;
}

void Info::Attributes::load(std::ifstream& file) {
	std::string line;
	getline(file, line);
	maxHP = stoi(parseString(line));
	attackDmg = stoi(parseString(line));
	speed = stoi(parseString(line));
	range = stoi(parseString(line));
	invSpace = stoi(parseString(line));
}

void Info::Attributes::clear() {
	maxHP = 0;
	attackDmg = 0;
	range = 0;
	speed = 0;
	invSpace = 0;
}

std::string Info::parseString(std::string& line, std::string delim) {
	size_t pos = 0;
	std::string info;

	pos = line.find(delim);
	info = line.substr(0, pos);
	line.erase(0, pos + delim.length());
	
	return info;//stoi(token);
}