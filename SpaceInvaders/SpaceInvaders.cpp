#include "SpaceInvaders.h"
#include "Game.h"
#include "Coord.h"
#include "Keyboard.h"
#include "RockUtiles.h"
#include "DifficultyMenu.h"
#include "Fighter.h"
#include "Collision.h"
#include "Martien.h"
#include "Vaisseau.h"
#include "SpaceSound.h"
#include "Laser.h"
#include <conio.h>
#include <time.h>
#include <iostream>
#include "FalconX.h"
#include "Destroyer.h"
using namespace std;

SpaceInvaders::SpaceInvaders() {
	this->pFalconX = &this->falconX;
	this->boucleDeplacement = 0;
	this->score = 0;
	this->timeSinceDestroyer = 0;
	this->destroyer = NULL;
	this->bomb = 0;
	this->nbAlienOut = 0;
	this->nbFighter = 3;
	this->maxFighter = 15;
	this->pNbFighter = &this->nbFighter;
	this->nbVie = 3;
	this->niveauDificulte = 45;
	this->initFalconX = 0;
	this->noElemLaser=0;
	this->maxElemLaser=50;
	this->laserFighter = new LaserFighter*[maxElemLaser];
	
}


SpaceInvaders::~SpaceInvaders() {

	for (int i = 0; i < nbFighter; i++) {
		if (tab[i] != NULL) {
		delete this->tab[i];
	}
	}
	for (int i = 0; i < this->noElemLaser; i++) {
		if (laserFighter[i] != NULL) {
			delete laserFighter[i];
		}
	}
	delete[] laserFighter;
	delete[] tab;

	delete destroyer;
	delete bomb;
}

void SpaceInvaders::start(int level) {
	
	ExtraTerrestre::resetNombreExtraTerrestre();
	this->tab = new Fighter*[this->maxFighter];

	//Initialization of Fighters
	for (int i = 0; i < nbFighter; i++) {
		this->tab[i] = new Fighter(1, 10);
		this->tab[i]->genererPosAleatoire();
	}

	//Initialisation du nombre de vie et du niveau de difficulte en fonction du choix du niveau
	if (level == 1) {
		this->nbVie = 3;
		this->niveauDificulte = 70;
	}
	else if (level == 2) {
		this->nbVie = 2;
		this->niveauDificulte = 45;
	}
	else if (level == 3) {
		this->nbVie = 1;
		this->niveauDificulte = 15;
	}

	system("cls");

	Coord::gotoXY(2, 2);
	cout << "Entrer le nom de joueur : ";
	cin >> nomDuJoueur;

	system("cls");
	
	if (level == 1) {
		Coord::gotoXY(2, 1);
		cout << "Soldat : " << nomDuJoueur;
	}
	else if (level == 2) {
		Coord::gotoXY(2, 1);
		cout << "Caporal : " << nomDuJoueur;
	}
	else if (level == 3) {
		Coord::gotoXY(2, 1);
		cout << "General : " << nomDuJoueur;
	}


	//When we start the spaceinvaders state, we should reset the variables
	//to their initial value, so the game restarts properly
	this->boucleDeplacement = 0;
	this->score = 0;
	this->timeSinceDestroyer = 0;
}

int SpaceInvaders::run() {

	incrementationBoucle();
	updateFalcon();
	updateDestroyer();

	// Affichage des Martiens
	for (int i = 0; i < this->nbFighter; i++) {
		if (this->tab[i] != NULL) {
			this->tab[i]->putExtraTerrestre();
		}
	}


	if (bomb != 0) {
		bomb->moveBomb();
		if (bomb->isAlive == false) {
			bomb->removeBomb();
			delete bomb;
			bomb = 0;
		}
		else {
			//the bomb exists and it's still alive. so lets test if it has hit the falcon
			bool hasBombHitSpaceship = collision.testBombDestroyerVsFalcon(bomb, pFalconX);

			if (hasBombHitSpaceship == true) {
				nbVie--;
				if (nbVie == 0) {
					Coord::gotoXY(30, 25);
					cout << "GAME OVER ! " << endl;
					system("PAUSE");

					return Game::MAIN_MENU_STATE;
				}
			}
		}
	}

	bool hasFighterHitSpaceship = collision.testFalconVsFighter(tab, pFalconX, &nbFighter);
	if (hasFighterHitSpaceship == true) {
		Coord::gotoXY(30, 25);
		cout << "GAME OVER ! " << endl;
		system("PAUSE");

		return Game::MAIN_MENU_STATE;
	}

	// Les Fightern jiggle toutes les 15 boucles.
	if (boucleDeplacement % 40 == 0) {
		for (int i = 0; i < this->nbFighter; i++) {
			if (this->tab[i] != NULL) {
				this->tab[i]->jiggleMartien();
			}
		}
	}
	this->randomFire =(rand() % this->nbFighter);
	if (boucleDeplacement % 10 == 0) {
		for (int i = 0; i < this->nbFighter; i++) {
			if (this->tab[i] != NULL&& i == this->randomFire) {
				fireLaser(this->tab[i]->getPositionX(), this->tab[i]->getPositionY());
			}
		}
	}

	// Deplacer vers le bas en fonction du niveau de difficulter;
	if (boucleDeplacement % niveauDificulte == 0) {
		for (int i = 0; i < this->nbFighter; i++) {
			if (this->tab[i] != NULL) {
				this->tab[i]->removeExtraTerrestre();
				this->tab[i]->deplacerBas();
			}
		}
	}


	for (int i = 0; i < this->noElemLaser; i++) {
		if (laserFighter[i] != NULL) {
			moveLaserFighter();
			removeLaser();
		}
	}

	// Verification de collision Extraterrestre/Terre.
	for (int i = 0; i < nbFighter; i++) {
		if (this->tab[i] != NULL) {
			if (this->tab[i]->coord.getPositionY() == 51) {
				delete tab[i];
				this->tab[i] = NULL;
				this->nbAlienOut++;
				alienOut.playAlienOutSound();
			}
		}
	}


	if (boucleDeplacement % 100 == 0) {
		if (this->nbFighter == this->maxFighter) {
			addMoreFighter();
		}
		this->tab[this->nbFighter] = new Fighter(1, 10);
		this->tab[this->nbFighter]->genererPosAleatoire();
		this->nbFighter++;

	}

	collision.testLaserFalconVsFighter(pFalconX, tab, pNbFighter);
	bool laserFighterVsFalcon;
	laserFighterVsFalcon = collision.testLaserFighterVsFalcon(pFalconX, laserFighter, noElemLaser);
	if (laserFighterVsFalcon == true) {
		nbVie--;
		if (nbVie == 0) {
			Coord::gotoXY(30, 25);
			cout << "GAME OVER ! " << endl;
			system("PAUSE");

			return Game::MAIN_MENU_STATE;
		}
	}

	printHeader();

	if (nbAlienOut == 3||this->nbFighter==15) {

		Coord::gotoXY(30, 25);
		cout << "GAME OVER ! ";
		system("PAUSE");
		this->nbAlienOut = 0;
		this->nbFighter = 3;
		return Game::MAIN_MENU_STATE;
	}
	if (ExtraTerrestre::getNombreExtraTerrestre() == 0) {
		Coord::gotoXY(30, 25);
		cout << "WINNER ! ";
		system("PAUSE");
		return Game::MAIN_MENU_STATE;
	}

	return Game::SPACE_INVADERS_STATE;
}

void SpaceInvaders::updateFalcon() {

	if (this->initFalconX == 0) {
		this->falconX.modifierPosition('a');
		this->initFalconX++;
	}

	//Movement de FalconX
	int key = Keyboard::recupererTouche();
	if (key == 'a' || key == 'd' || key == 32) {
		this->falconX.modifierPosition(key);
	}

	this->falconX.moveLaserLeft();
	this->falconX.moveLaserRight();
	this->falconX.removeLaserLeft();
	this->falconX.removeLaserRight();
}

void SpaceInvaders::updateDestroyer() {
	timeSinceDestroyer++;

	//Aparition de destroyer
	if (timeSinceDestroyer > 50) {
		if (destroyer == NULL) {
			destroyer = new Destroyer('=', 100);
			destroyer->setDestroyerPos(1, 5);
		}

		if (destroyer != NULL && destroyer->isAlive == true) {
			timeSinceDestroyer = 51;
			destroyer->putDestroyer();
			if (boucleDeplacement % 3 == 0) {
				this->destroyer->removeDestroyer();
				this->destroyer->deplacerDestroyer();

				int destroyerXpos = destroyer->coord.getPositionX();
				if (destroyerXpos == 95) {
					destroyer->removeDestroyer();
					destroyer->setDestroyerPos(1, 5);
					timeSinceDestroyer = 0;
				}
				else {
					if (bomb == 0) {
						if (destroyerXpos == falconX.coord.getPositionX()) {
							bomb = new Bomb;
							bomb->startBomb(destroyerXpos);
						}
					}
				}
			}
		}
	}

	bool hasSpaceshipHitDestroyer = collision.testLaserFalconVsDestroyer(pFalconX, destroyer);
	if (hasSpaceshipHitDestroyer == true) {
		destroyer->hitByFalcon();
	}
}

void SpaceInvaders::printHeader() {
	Coord::gotoXY(44, 1);
	cout << "Ennemies Restants : ";
	cout << ExtraTerrestre::getNombreExtraTerrestre() << " ";

	Coord::gotoXY(22, 1);
	cout << "Nombre de Vie : " << nbVie;


	Coord::gotoXY(72, 1);
	cout << "Ennemies Passer : ";
	cout << nbAlienOut;
	Coord::gotoXY(0, 2);
	cout << "_____________________________________________________________________________________________________";

}

void SpaceInvaders::incrementationBoucle() {
	this->boucleDeplacement++;
}
void SpaceInvaders::addMoreFighter() {
	Fighter** temp = new Fighter*[this->maxFighter * 2];
	for (int i = 0; i < this->nbFighter; i++) {
		temp[i] = tab[i];
	}
	delete[]tab;
	tab = temp;
	this->maxFighter *= 2;
}


void SpaceInvaders::fireLaser(int x, int y) {
	if (this->noElemLaser == this->maxElemLaser) {
		addLaserArray();
	}
	this->laserFighter[this->noElemLaser] = new LaserFighter;
	this->laserFighter[this->noElemLaser]->startLaser(x, y);
	this->noElemLaser++;
}
void SpaceInvaders::addLaserArray() {
	LaserFighter ** temp = new LaserFighter*[this->maxElemLaser * 2];
	for (int i = 0; i < this->noElemLaser; i++) {
		temp[i] = this->laserFighter[i];
	}
	delete[]laserFighter;
	this->laserFighter = temp;
	this->maxElemLaser *= 2;
}

void SpaceInvaders::moveLaserFighter() {
	for (int i = 0; i < this->noElemLaser; i++) {
		if (this->laserFighter[i] != NULL && this->laserFighter[i]->isAlive == true) {
			this->laserFighter[i]->moveLaserDown();
		}
	}
}
void SpaceInvaders::removeLaser() {
	for (int i = 0; i < this->noElemLaser; i++) {
		if (this->laserFighter[i] != NULL &&this->laserFighter[i]->coord.getPositionY() == 51) {
			this->laserFighter[i]->removeLaser();
			delete laserFighter[i];
			this->laserFighter[i] = NULL;
		}
	}
}