#pragma once
#include "Coord.h"
#include "FalconLaser.h"
#include "SpaceSound.h"
#include "Vaisseau.h"
class FalconX: public Vaisseau{
	int maxElementLaserLeft;
	int noElementLaserLeft;
	int maxElementLaserRight;
	int noElementLaserRight;
	FalconLaser** laserRight;
	FalconLaser** laserLeft;
	SpaceSound laserSound;
protected:
	void removeVaisseau() const;
	void putVaisseau() const;

public:
	FalconX();
	~FalconX();
	void modifierPosition(char);
	void fireLaser();
	void moveLaserLeft();
	void removeLaserLeft();
	void moveLaserRight();
	void removeLaserRight();
	void addLaserArrayLeft();
	void addLaserArrayRight();
	void ajustArraySizeLaserLeft();
	void ajustArraySizeLaserRight();

	//laser left
	int getNoElementLaserLeft();
	int getPositionXLaserLeft(int indice);
	int getPositionYLaserLeft(int indice);
	//laser right
	int getNoElementLaserRight();
	int getPositionXLaserRight(int indice);
	int getPositionYLaserRight(int indice);
	int getFalconXposX();
	int getFalconXposY();
	bool isAlive;
};