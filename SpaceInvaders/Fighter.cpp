#include "Fighter.h"
#include "Laser.h"
#include "LaserFighter.h"
#include "Coord.h"
#include <iostream>

Fighter::Fighter(int type, int valeur) : Martien(type, valeur) {
}

void Fighter::genererPosAleatoire() {
	coord.setPositionX((rand() % (100 - 1) - 2 + 2) + 2);
	coord.setPositionY((rand() % (20 - 1) - 2 + 2) + 3);
	isAlive = true;
	nombreExtraTerrestre++;
}
void Fighter::deplacerBas() {
	coord.setPositionY(coord.getPositionY() + 1);
}

int Fighter::getPositionX() {
	return this->coord.getPositionX();
}
int Fighter::getPositionY() {
	return this->coord.getPositionY();
}


