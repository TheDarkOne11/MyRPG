#ifndef LOADMENU_H
#define LOADMENU_H

#include <fstream>
#include "Info.h"
#include "Menu.h"

class LoadMenu {
public:
	LoadMenu();
	
	void paint(Screen* screen);
	
	/**
	 * Update load menu.
	 * @param fileName is the fileName of the chosen file. Set in update.
	 * @return 1 if level was chosen, 0 if player went out of load menu (ESC), -1 otherwise.
	 */
	int update(std::string& fileName);
private:
	Menu fileNamesMenu;
	std::vector<std::string> vect_FileNames;
	
	void reloadChoices();
};

#endif /* LOADMENU_H */

