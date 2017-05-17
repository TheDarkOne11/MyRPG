#ifndef MSGBOX_H
#define MSGBOX_H

#include <vector>
#include <iostream>
#include "Screen.h"

class MsgBox {
public:
	MsgBox(int max);
	
	/**
	* Adds message that is to be written to the info screen
	* @param msg
	*/
	void addMsg(std::string msg);
	
	const std::vector<std::string> getMsgBuffer();
private:
	int max;
	int msgCount;
	std::vector<std::string> msgBuffer;
};

#endif /* MSGBOX_H */

