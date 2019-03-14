#pragma once
#include "Screen.h"
#include "Clock.h"
#include "Keyboard.h"
#include "MainMenu.h"
#include "DifficultyMenu.h"
#include "SpaceInvaders.h"

class Game
{
public:
	Game();
	~Game();
	void setup();
	void run();
	int getLevel();
	static const int MAIN_MENU_STATE = 0;
	static const int DIFFICULTY_MENU_STATE = 1;
	static const int SPACE_INVADERS_STATE = 2;
	static const int QUIT_GAME = 3;

private:
	bool runLogic();

	Screen screen;
	Keyboard keyboard;
	Clock clock;
	MainMenu mainMenu;
	DifficultyMenu difficultyMenu;
	SpaceInvaders *spaceInvaders;
	int state;
	int prevState;
	void startNewGame();
	void addMoreGame();
};