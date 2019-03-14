#pragma once

#include "Coord.h"

class Bomb
{


public:
	bool isAlive;
	Coord coord;

	void startBomb(int);
	void removeBomb() const;
	void putBomb() const;
	virtual void moveBomb();
	void killBomb();
	int getBombposX();
	int getBombposY();
};

