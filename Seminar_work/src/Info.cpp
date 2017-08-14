#include "Info.h"

const std::string Info::pathDirMaps = "./res/maps";
const std::string Info::pathDirSaves = "./res/saves";
const std::string Info::pathNamesMaps = pathDirMaps + "/" + "fileNames";
const std::string Info::pathNamesSaves = pathDirSaves + "/" + "fileNames";

std::string Info::parseString(std::string& line, const std::string delim) {
	size_t pos = 0;
	std::string info;

	pos = line.find(delim);
	info = line.substr(0, pos);
	line.erase(0, pos + delim.length());
	
	return info;//stoi(token);
}