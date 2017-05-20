#include "Game.h"

Game::Game() : currState(MAIN_MENU), mainMenu("MAIN MENU") {
	// Init ncurses screen
	screen = new Screen();
	
	Handler::init();
	
	// TODO Load Main Menu
	ChoiceVect choices;
	choices.push_back( std::make_pair("New Game", NEW_LEVELS) );
	choices.push_back( std::make_pair("Exit application", EXIT) );
	mainMenu.setChoices(choices);	
}

Game::~Game() {
	Handler::clear();
	delete screen;
}

void Game::update() {
	int tmp;
	UserInput::update();
	screen->update();
	
	switch(currState) {
		case(MAIN_MENU):
			screen->setCurrScreen(screen->STANDARD);
			tmp = mainMenu.update();
			if(tmp != -1) {
				// New state was chosen
				currState = (GameState) tmp;
			}
			
			break;
		case(NEW_LEVELS):
			levels = new Levels(screen);
			currState = LEVELS;
			break;
		case(LEVELS):
			levels->update();
			if(levels->getLevelState() == levels->EXIT) {
				currState = LEVELS_ENDED;
			}
			break;
		case(LEVELS_ENDED):
			delete levels;
			currState = MAIN_MENU;
			break;
		case(EXIT):
			break;
	}
	
}

void Game::paint() {
	screen->sClear();
	
	switch(currState) {
		case(MAIN_MENU):
			mainMenu.paint(screen);
			break;
		case(NEW_LEVELS):
			
			break;
		case(LEVELS): 
			levels->paint();
			break;
		case(LEVELS_ENDED):
			
			break;
		case(EXIT):
			break;
	}
	
	screen->sRefresh();
}

bool Game::isRunning() const {
	return currState != GameState::EXIT;
}