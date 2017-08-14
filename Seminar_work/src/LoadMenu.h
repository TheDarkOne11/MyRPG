#ifndef LOADMENU_H
#define LOADMENU_H

#include <fstream>
#include "Info.h"
#include "Menu.h"

/**
 * Class handles special menu for loading games from saved files.
 */
class LoadMenu {
public:
	LoadMenu();
	
	/**
	 * Paints all avaible saved files.
	 * @param screen
	 */
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
	bool isUpdated;		///< True if Load menu has been updated.
	
	/**
	 * Reloades available save files.
	 */
	void reloadChoices();
};

#endif /* LOADMENU_H */

