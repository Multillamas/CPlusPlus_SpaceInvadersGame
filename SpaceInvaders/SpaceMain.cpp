#include "Game.h"
#include <time.h>
#include<iostream>

int main()
{ 
	srand(time(NULL));
	Game game;
	game.setup();
	game.run();

	
	return 0;
}