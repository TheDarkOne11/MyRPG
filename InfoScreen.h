#ifndef INFOPANEL_H
#define INFOPANEL_H

#include <vector>
#include "Info.h"

/**
 * Handles game info panel
 */
class InfoScreen {
public:
	InfoScreen();
	
	void update();
	
	void paint();
	
	void addMsg(std::string msg);
private:
	
	std::vector<std::string> msgBuffer;
};

#endif /* INFOPANEL_H */

