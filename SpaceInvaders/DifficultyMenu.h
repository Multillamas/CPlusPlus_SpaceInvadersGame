#pragma once

#include "SpaceSound.h"
class DifficultyMenu
{
	int level;
	SpaceSound spaceSound;
public:
	void start();
	int run();
	void setLevel(int level);
	int getLevel();
	
};