#include "FalconX.h"
#include "FalconLaser.h"
#include <iostream>
using namespace std;

void FalconX::removeVaisseau() const
{
	coord.gotoXY(coord.getPositionX(), coord.getPositionY());
	cout << " ";
	coord.gotoXY(coord.getPositionX() + 1, coord.getPositionY());
	cout << " ";
	coord.gotoXY(coord.getPositionX() + 2, coord.getPositionY());
	cout << " ";
	coord.gotoXY(coord.getPositionX() + 3, coord.getPositionY());
	cout << " ";
	coord.gotoXY(coord.getPositionX() + 4, coord.getPositionY());
	cout << " ";
	coord.gotoXY(coord.getPositionX(), coord.getPositionY() - 1);
	cout << " ";
	coord.gotoXY(coord.getPositionX() + 1, coord.getPositionY() - 1);
	cout << " ";
	coord.gotoXY(coord.getPositionX() + 2, coord.getPositionY() - 1);
	cout << " ";
	coord.gotoXY(coord.getPositionX() + 3, coord.getPositionY() - 1);
	cout << " ";
	coord.gotoXY(coord.getPositionX() + 4, coord.getPositionY() - 1);
	cout << " ";
	coord.gotoXY(coord.getPositionX(), coord.getPositionY() - 2);
	cout << " ";
	coord.gotoXY(coord.getPositionX() + 2, coord.getPositionY() - 2);
	cout << " ";
	coord.gotoXY(coord.getPositionX() + 4, coord.getPositionY() - 2);
	cout << " ";
	coord.gotoXY(coord.getPositionX(), coord.getPositionY() - 3);
	cout << " ";
	coord.gotoXY(coord.getPositionX() + 4, coord.getPositionY() - 3);
	cout << " ";
}

void FalconX::putVaisseau() const
{
	coord.gotoXY(coord.getPositionX(), coord.getPositionY());
	cout << char(219);
	coord.gotoXY(coord.getPositionX() + 1, coord.getPositionY());
	cout << char(219);
	coord.gotoXY(coord.getPositionX() + 2, coord.getPositionY());
	cout << char(219);
	coord.gotoXY(coord.getPositionX() + 3, coord.getPositionY());
	cout << char(219);
	coord.gotoXY(coord.getPositionX() + 4, coord.getPositionY());
	cout << char(219);
	coord.gotoXY(coord.getPositionX(), coord.getPositionY() - 1);
	cout << char(219);
	coord.gotoXY(coord.getPositionX() + 1, coord.getPositionY() - 1);
	cout << char(219);
	coord.gotoXY(coord.getPositionX() + 2, coord.getPositionY() - 1);
	cout << char(219);
	coord.gotoXY(coord.getPositionX() + 3, coord.getPositionY() - 1);
	cout << char(219);
	coord.gotoXY(coord.getPositionX() + 4, coord.getPositionY() - 1);
	cout << char(219);
	coord.gotoXY(coord.getPositionX(), coord.getPositionY() - 2);
	cout << char(219);
	coord.gotoXY(coord.getPositionX() + 4, coord.getPositionY() - 2);
	cout << char(219);
	coord.gotoXY(coord.getPositionX(), coord.getPositionY() - 3);
	cout << char(219);
	coord.gotoXY(coord.getPositionX() + 4, coord.getPositionY() - 3);
	cout << char(219);
}

FalconX::FalconX()
{
	coord.setPositionX(47);
	coord.setPositionY(49);

	this->isAlive = true;
	this->maxElementLaserLeft = 1;
	this->noElementLaserLeft = 0;
	this->maxElementLaserRight = 1;
	this->noElementLaserRight = 0;
	this->laserLeft = new FalconLaser*[maxElementLaserLeft];
	this->laserRight = new FalconLaser*[maxElementLaserRight];
}
FalconX::~FalconX() {

	for (int i = 0; i < this->noElementLaserLeft; i++) {
		delete this->laserLeft[i];
	}
	for (int i = 0; i < this->noElementLaserRight; i++) {
		delete this->laserRight[i];
	}
	delete[] this->laserLeft;
	delete[] this->laserRight;
}
void FalconX::modifierPosition(char key)
{
	removeVaisseau();
	switch (key)
	{
	case 'a':
		if (coord.getPositionX() > 0) {
			coord.setPositionX(coord.getPositionX() - 1);
		}
		break;
	case 'd':
		if (coord.getPositionX() < 95) {
			coord.setPositionX(coord.getPositionX() + 1);
		}
		break;
	case 32:  this->fireLaser();
	}
	putVaisseau();
}
void FalconX::addLaserArrayLeft() {
	FalconLaser ** temp = new FalconLaser*[this->maxElementLaserLeft * 2];

	for (int i = 0; i < this->noElementLaserLeft; i++) {
		temp[i] = this->laserLeft[i];
	}
	delete[]laserLeft;
	this->laserLeft = temp;
	this->maxElementLaserLeft *= 2;
}
void FalconX::addLaserArrayRight() {
	FalconLaser ** temp = new FalconLaser*[this->maxElementLaserRight * 2];
	for (int i = 0; i < this->noElementLaserRight; i++) {
		temp[i] = this->laserRight[i];
	}
	delete[]laserRight;
	this->laserRight = temp;
	this->maxElementLaserRight *= 2;
}
void FalconX::fireLaser() {
	if (noElementLaserLeft == 50) {
		ajustArraySizeLaserLeft();
	}
	if (noElementLaserRight == 50) {
		ajustArraySizeLaserRight();
	}
	if (noElementLaserLeft == maxElementLaserLeft) {
		addLaserArrayLeft();
	}
	if (noElementLaserRight == maxElementLaserRight) {
		addLaserArrayRight();
	}
	this->laserLeft[noElementLaserLeft] = new FalconLaser;
	this->laserRight[noElementLaserRight] = new FalconLaser;
	this->laserLeft[noElementLaserLeft]->startLaserLeft(this->coord.getPositionX(), this->coord.getPositionY() - 4);
	this->laserRight[noElementLaserRight]->startLaserRight(this->coord.getPositionX() + 4, this->coord.getPositionY() - 4);
	this->laserSound.playLaserSound();
	this->noElementLaserLeft++;
	this->noElementLaserRight++;
}
void FalconX::moveLaserLeft() {
	for (int i = 0; i < this->noElementLaserLeft; i++) {
		if (this->laserLeft[i] != NULL && this->laserLeft[i]->isAlive == true) {
			this->laserLeft[i]->moveLaser();
		}
	}
}
void FalconX::removeLaserLeft() {
	for (int i = 0; i < this->noElementLaserLeft; i++) {
		if (this->laserLeft[i] != NULL &&this->laserLeft[i]->coord.getPositionY() == 2) {
			this->laserLeft[i]->killLaser();
			delete laserLeft[i];
			this->laserLeft[i] = NULL;
		}
	}
}
void FalconX::moveLaserRight() {
	for (int i = 0; i < this->noElementLaserRight; i++) {
		if (this->laserRight[i] != NULL && this->laserRight[i]->isAlive == true) {
			this->laserRight[i]->moveLaser();
		}
	}
}
void FalconX::removeLaserRight() {
	for (int i = 0; i < this->noElementLaserRight; i++) {
		if (this->laserRight[i] != NULL &&this->laserRight[i]->coord.getPositionY() == 2) {
			this->laserRight[i]->killLaser();
			delete laserRight[i];
			this->laserRight[i] = NULL;
		}
	}
}
void FalconX::ajustArraySizeLaserLeft() {
	int newNoElement = 0;
	for (int i = 0; i < this->noElementLaserLeft; i++) {
		if (laserLeft[i] != NULL) {
			newNoElement++;
		}
	}
	FalconLaser** temp = new FalconLaser*[newNoElement];
	int cpt = 0;
	for (int i = 0; i < this->noElementLaserLeft; i++) {
		if (laserLeft[i] != NULL) {
			temp[cpt] = laserLeft[i];
			cpt++;
		}
	}
	delete[] this->laserLeft;
	this->laserLeft = temp;
	this->noElementLaserLeft = newNoElement;
	this->maxElementLaserLeft = newNoElement;
}
void FalconX::ajustArraySizeLaserRight() {
	int newNoElement = 0;
	for (int i = 0; i < this->noElementLaserRight; i++) {
		if (laserRight[i] != NULL) {
			newNoElement++;
		}
	}
	FalconLaser** temp = new FalconLaser*[newNoElement];
	int cpt = 0;
	for (int i = 0; i < this->noElementLaserRight; i++) {
		if (laserRight[i] != NULL) {
			temp[cpt] = laserRight[i];
			cpt++;
		}
	}
	delete[] this->laserRight;
	this->laserRight = temp;
	this->noElementLaserRight = newNoElement;
	this->maxElementLaserRight = newNoElement;
}
int FalconX::getNoElementLaserLeft() {
	return this->noElementLaserLeft;
}
int FalconX::getNoElementLaserRight() {
	return this->noElementLaserRight;
}
int FalconX::getPositionXLaserLeft(int indice) {
	if (laserLeft[indice] != NULL) {
		return this->laserLeft[indice]->coord.getPositionX();
	}
	else {
		return 0;
	}
}

int FalconX::getPositionYLaserLeft(int indice) {
	if (laserLeft[indice] != NULL) {
		return this->laserLeft[indice]->coord.getPositionY();
	}
	else {
		return 0;
	}
}
int  FalconX::getFalconXposX() {
	return coord.getPositionX();
}

int  FalconX::getFalconXposY() {
	return coord.getPositionY();
}

int FalconX::getPositionXLaserRight(int indice) {
	if (laserRight[indice] != NULL) {
		return this->laserRight[indice]->coord.getPositionX();
	}
	else {
		return 0;
	}
}
int FalconX::getPositionYLaserRight(int indice) {
	if (laserRight[indice] != NULL) {
		return this->laserRight[indice]->coord.getPositionY();
	}
	else {
		return 0;
	}

}

