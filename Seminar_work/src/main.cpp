#include <cstdlib>
#include <iostream>
#include <unistd.h>

#include "Game.h"

using namespace std;

int main(int argc, char** argv) {
	Game game;
	int fps = 60;
	int sleepTime = 1000000/fps;	///< Sleep time should give us 60 FPS
	
	// Main game loop
	while( game.isRunning() ) {
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
		
		// Sleep
		usleep(sleepTime);	
	}
	
	return 0;
}

