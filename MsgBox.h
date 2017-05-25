#ifndef MSGBOX_H
#define MSGBOX_H

#include <vector>
#include <iostream>
#include "Screen.h"

/**
 * Class serves as a Message box. It stores all messages that should be painted on the screen.
 */
class MsgBox {
public:
	/**
	 * Standard constructor.
	 * @param max is the maximum number of messages class should store.
	 */
	MsgBox(int max);
	
	/**
	* Adds message that is to be written to the info screen
	* @param msg
	*/
	void addMsg(std::string msg);
	
	/**
	 * @return All messages.
	 */
	const std::vector<std::string> getMsgBuffer();
private:
	int max;		///< Maximum number of messages stored.
	int msgCount;	///< Current count of messages stored.
	std::vector<std::string> msgBuffer;	///< Stored messages.
};

#endif /* MSGBOX_H */

