#include <cstdlib>
#include <iostream>
#include <ncurses.h>
#include <unistd.h>

#include "Game.h"

using namespace std;

int main(int argc, char** argv) {
	Game game;
	int fps = 60;
	int sleepTime = 1000000/fps;	// TODO Count sleepTime
	
	// Main game loop
	while( game.isRunning() ) {
		game.update();
		game.paint();
		
		usleep(sleepTime);	
	}
	
	return 0;
}

