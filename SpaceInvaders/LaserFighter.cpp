#include "LaserFighter.h"
#include "Laser.h"
#include <iostream>
void LaserFighter::moveLaserDown(){
	
		removeLaser();
		if (coord.getPositionY()>0)
		{
			coord.setPositionY(coord.getPositionY() + 1);
			putLaser();
		}
		else
			isAlive = false;
	
}
void LaserFighter::removeLaser() const
{
	coord.gotoXY(coord.getPositionX(), coord.getPositionY());
	std::cout << " ";
}

void LaserFighter::putLaser() const
{
	coord.gotoXY(coord.getPositionX(), coord.getPositionY());
	std::cout << char(15);
}
void LaserFighter::startLaser(int x, int y) {
	coord.setPositionX(x);
	coord.setPositionY(y);
	putLaser();
	isAlive = true;
}
int LaserFighter::getPositionX() {
	return this->coord.getPositionX();
}
int LaserFighter::getPositionY() {
	return this->coord.getPositionY();
}