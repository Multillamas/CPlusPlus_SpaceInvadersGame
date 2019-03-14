#include "Game.h"
#include <stdlib.h>

Game::Game(){
	//the first state is going to be the main menu.
	//we will set the previous state to be invalid
	this->state = MAIN_MENU_STATE;
	this->prevState = -1;
	this->spaceInvaders = NULL;
}
Game::~Game() {
	delete spaceInvaders;
}
void Game::setup(){
	screen.setupSize(100, 50);
}

void Game::run(){
	int frameTime = 1000 / 30; //value in ms for the countdown

	//while loops it keeps the game running
	while (true) {
		clock.startCountdown(frameTime);	
		if (runLogic() == false) {
			break;
		}
		clock.waitForCountdown();
	}
}

bool Game::runLogic() {

	if (state != prevState) {
		prevState = state;

		switch (state) {
		case MAIN_MENU_STATE:
			mainMenu.start(screen);
			break;

		case DIFFICULTY_MENU_STATE:
			difficultyMenu.start();
			break;

		case SPACE_INVADERS_STATE:
			startNewGame();
			spaceInvaders->start(difficultyMenu.getLevel());
			break;

		case QUIT_GAME:
			return false;
		}
	}

	switch (state) {
	case MAIN_MENU_STATE:
		state = mainMenu.run(); //run returns what state the game is
		break;

	case DIFFICULTY_MENU_STATE:
		state = difficultyMenu.run();
		break;

	case SPACE_INVADERS_STATE:
		state = spaceInvaders->run();
		break;

	case QUIT_GAME:
		return false;
	}

	return true;
}
void Game::startNewGame() {
	if (this->spaceInvaders != NULL) {
		delete this->spaceInvaders;
	}

	this->spaceInvaders = new SpaceInvaders;
}

int Game::getLevel() {
	return this->difficultyMenu.getLevel();
}
