#include "MsgBox.h"

MsgBox::MsgBox(int max) : max(max), msgCount(0), msgBuffer(max) {
}

void MsgBox::addMsg(const std::string msg) {
	// Number of msgs info screen can show: infoScreenHeight - playerInfoRow
	int pos = msgCount % max;
	msgBuffer.at(pos) = msg;
	msgCount++;
}

const std::vector<std::string> MsgBox::getMsgBuffer() const {
	return msgBuffer;
}
