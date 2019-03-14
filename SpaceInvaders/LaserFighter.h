#pragma once
#include "Laser.h"
class LaserFighter:public Laser {
public:
	void startLaser(int x, int y);
	bool isAlive;
	Coord coord;
	void moveLaserDown();
	void removeLaser() const;
	void putLaser() const;
	int getPositionX();
	int getPositionY();
};