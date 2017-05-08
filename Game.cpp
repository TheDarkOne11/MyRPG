#include "Game.h"

Game::Game() {
	currState = MAIN_MENU;
}

Game::~Game() {
}

void Game::update() {
	
}

void Game::paint() {
	
}

bool Game::isRunning() {
	return currState != currState.EXIT;
}