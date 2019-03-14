#pragma once
#include "Destroyer.h"
#include "Vaisseau.h"
#include "Fighter.h"
#include "Bomb.h"
#include "Collision.h"
#include "SpaceSound.h"
#include "FalconX.h"
#include <string>

class SpaceInvaders
{
public:
	SpaceInvaders();
	~SpaceInvaders();
	std::string nomDuJoueur;
	void start(int level);
	int run();
	int nbFighter;
	int maxFighter;
	int *pNbFighter;
	SpaceSound alienOut;
	void incrementationBoucle();
	void fireLaser(int x, int y);
	void addLaserArray();
	void moveLaserFighter();
	void removeLaser();
private:
	void updateFalcon();
	void updateDestroyer();
	void printHeader();
	void addMoreFighter();

	Collision collision;
	Destroyer* destroyer;
	int boucleDeplacement;
	int timeSinceDestroyer;
	FalconX falconX;
	FalconX* pFalconX;
	int score;
	int nbVie;
	int niveauDificulte;
	int nbAlienOut;
	int randomFire;
	int initFalconX;
	Fighter** tab;
	Bomb* bomb;

	LaserFighter** laserFighter;
	int noElemLaser;
	int maxElemLaser;
};