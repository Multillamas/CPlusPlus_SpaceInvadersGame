#pragma once
#include "Screen.h"
#include "SpaceSound.h"

class MainMenu
{
	SpaceSound spaceSound;
public:
	void start(Screen& screen);
	int run();
};