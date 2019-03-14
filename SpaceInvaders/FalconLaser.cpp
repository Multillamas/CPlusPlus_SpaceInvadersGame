#include "FalconLaser.h"
#include "Laser.h"
void FalconLaser::startLaserLeft(int x, int y) {
	coord.setPositionX(x);
	coord.setPositionY(y);
	putLaser();
	isAlive = true;
}
void FalconLaser::startLaserRight(int x, int y) {
	coord.setPositionX(x);
	coord.setPositionY(y);
	putLaser();
	isAlive = true;
}