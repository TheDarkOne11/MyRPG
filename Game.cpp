#include "Game.h"

Game::Game() {
	currState = GameState::MAIN_MENU;
}

Game::~Game() {
}

void Game::update() {
}

void Game::paint() {
}

bool Game::isRunning() {
	return currState != GameState::EXIT;
}