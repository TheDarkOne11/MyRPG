#include <cstdlib>
#include <iostream>
#include <unistd.h>

#include "Game.h"

using namespace std;

int main(int argc, char** argv) {
	Game game;
	int fps = 60;
	int sleepTime = 1000000/fps;	// TODO Count sleepTime
	
	// Main game loop
	while( game.isRunning() ) {
		// TODO Make exception handling somewhere else
		try {
			game.update();
			game.paint();
		} catch(const char* s) {
			cerr << s << endl;
			break;
		} catch(string s) {
			cerr << s << endl;
			break;
		} catch(std::out_of_range e) {
			cerr << e.what() << endl;
			break;
		}
		
		usleep(sleepTime);	
	}
	
	return 0;
}

