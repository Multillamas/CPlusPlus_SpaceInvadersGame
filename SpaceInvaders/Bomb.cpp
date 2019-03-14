#include "Bomb.h"
#include <iostream>
using namespace std;

void Bomb::startBomb(int x)
{
	coord.setPositionX(x);
	coord.setPositionY(4);
	putBomb();
	isAlive = true;
}

void Bomb::removeBomb() const
{
	coord.gotoXY(coord.getPositionX(), coord.getPositionY());
	cout << " ";
}

void Bomb::putBomb() const
{
	coord.gotoXY(coord.getPositionX(), coord.getPositionY());
	cout << char(15);
}

void Bomb::moveBomb()
{
	removeBomb();
	if (coord.getPositionY()<49)
	{
		coord.setPositionY(coord.getPositionY() + 1);
		putBomb();
	}
	else
		isAlive = false;
}

void Bomb::killBomb()
{
	removeBomb();
	isAlive = false;
}
int Bomb::getBombposX() {
	return this->coord.getPositionX();
}
int Bomb::getBombposY() {
	return this->coord.getPositionY();
}
