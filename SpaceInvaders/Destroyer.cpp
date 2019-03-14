#include "Destroyer.h"
#include<iostream>
using namespace std;
Destroyer::Destroyer(int type, int valeur) : ExtraTerrestre(type, valeur) {
	this->viesDestroyer = 300;
	this->isAlive = true;
}

Destroyer::~Destroyer() {
}
void Destroyer::setDestroyerPos(int x, int y){
	this->coord.setPositionX(x);
	this->coord.setPositionY(y);
}
int Destroyer::getDestroyerPosX(){
	return this->coord.getPositionX();
}
int Destroyer::getDestroyerPosY(){
	
	return this->coord.getPositionY();
}
void Destroyer::putDestroyer() {
	coord.gotoXY(coord.getPositionX(),coord.getPositionY());
	cout << char(201);

	coord.gotoXY(coord.getPositionX() + 1, coord.getPositionY());
	cout << char(205);

	coord.gotoXY(coord.getPositionX() + 2, coord.getPositionY());
	cout << char(187);

	coord.gotoXY(coord.getPositionX(), coord.getPositionY() + 1);
	cout << char(200);

	coord.gotoXY(coord.getPositionX() + 1, coord.getPositionY() + 1);
	cout << char(205);

	coord.gotoXY(coord.getPositionX() + 2, coord.getPositionY() + 1);
	cout << char(188);

	coord.gotoXY(coord.getPositionX() - 1, coord.getPositionY() - 1);
	cout << '\\';
	coord.gotoXY(coord.getPositionX() - 1, coord.getPositionY() + 2);
	cout << '/';
	coord.gotoXY(coord.getPositionX() + 3, coord.getPositionY() - 1);
	cout << '/';
	coord.gotoXY(coord.getPositionX() + 3, coord.getPositionY() + 2);
	cout << '\\';
}

void Destroyer::removeDestroyer() {
	coord.gotoXY(coord.getPositionX(), coord.getPositionY());
	cout << ' ';

	coord.gotoXY(coord.getPositionX() + 1, coord.getPositionY());
	cout << ' ';

	coord.gotoXY(coord.getPositionX() + 2, coord.getPositionY());
	cout << ' ';

	coord.gotoXY(coord.getPositionX(), coord.getPositionY() + 1);
	cout << ' ';

	coord.gotoXY(coord.getPositionX() + 1, coord.getPositionY() + 1);
	cout << ' ';

	coord.gotoXY(coord.getPositionX() + 2, coord.getPositionY() + 1);
	cout << ' ';

	coord.gotoXY(coord.getPositionX() - 1, coord.getPositionY() - 1);
	cout << ' ';
	coord.gotoXY(coord.getPositionX() - 1, coord.getPositionY() + 2);
	cout << ' ';
	coord.gotoXY(coord.getPositionX() + 3, coord.getPositionY() - 1);
	cout << ' ';
	coord.gotoXY(coord.getPositionX() + 3, coord.getPositionY() + 2);
	cout << ' ';
}
void Destroyer::deplacerDestroyer() {
	coord.setPositionX(coord.getPositionX() + 1);
}

void Destroyer::KillDestroyer() {
	removeDestroyer();
	isAlive = false;
}

void Destroyer::hitByFalcon() {
	this->viesDestroyer -= 100;
	if (this->viesDestroyer <= 0) {
    		KillDestroyer();
	}
}