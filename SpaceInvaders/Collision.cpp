#include "Collision.h"
#include "FalconX.h"
#include "ExtraTerrestre.h".
#include "Fighter.h"
#include "Destroyer.h"
bool Collision::testFalconVsFighter(Fighter* tab[], FalconX* pFalconx, int* nbFighter) {
	for (int i = 0; i < *nbFighter; i++) {
		if (tab[i] != NULL) {
			if (tab[i]->coord.getPositionY() >= pFalconx->getFalconXposY() - 4) {
				int fighterX = tab[i]->coord.getPositionX();
				if (fighterX >= pFalconx->getFalconXposX() && fighterX <= (pFalconx->getFalconXposX() + 4)) {
					return true;
				}
			}
		}
	}
	return false;
}
void Collision::testLaserFalconVsFighter(FalconX* pFalconx, Fighter* tab[], int* nbFighter) {
	bool collision = false;
	for (int i = 0; i < *nbFighter; i++) {
		for (int j = 0; j < pFalconx->getNoElementLaserLeft() && collision == false; j++) {
			if (tab[i] != NULL&&tab[i]->getPositionX() == pFalconx->getPositionXLaserLeft(j) && tab[i]->getPositionY() == pFalconx->getPositionYLaserLeft(j)) {
				tab[i]->removeExtraTerrestre();
				collision = true;
				delete tab[i];
				tab[i] = NULL;
				ExtraTerrestre::reduireNombreExtraTerrestre();
				spaceSound.explosionSound();

			}
		}
		for (int k = 0; k < pFalconx->getNoElementLaserRight() && collision == false; k++) {
			if (tab[i] != NULL&&tab[i]->getPositionX() == pFalconx->getPositionXLaserRight(k) && tab[i]->getPositionY() == pFalconx->getPositionYLaserRight(k)) {
				tab[i]->removeExtraTerrestre();
				collision = true;
				delete tab[i];
				tab[i] = NULL;
				ExtraTerrestre::reduireNombreExtraTerrestre();
			}
		}
	}


}
bool Collision::testLaserFighterVsFalcon(FalconX* pFalconx, LaserFighter* laser[], int nbLaser) {
			for (int i = 0; i < nbLaser; i++) {
			if ((laser[i] != NULL&&laser[i]->getPositionX() == pFalconx->getFalconXposX() && laser[i]->getPositionY() == pFalconx->getFalconXposY() - 4)||
				(laser[i] != NULL && laser[i]->getPositionX() == (pFalconx->getFalconXposX()+1) && laser[i]->getPositionY() == (pFalconx->getFalconXposY() - 1))||
				(laser[i] != NULL && laser[i]->getPositionX() == (pFalconx->getFalconXposX()+2) && laser[i]->getPositionY() == (pFalconx->getFalconXposY() - 1))||
				(laser[i] != NULL && laser[i]->getPositionX() == (pFalconx->getFalconXposX()+3) && laser[i]->getPositionY() == (pFalconx->getFalconXposY() - 1))||
				(laser[i] != NULL && laser[i]->getPositionX() == (pFalconx->getFalconXposX()+4) && laser[i]->getPositionY() == (pFalconx->getFalconXposY() - 1))||
				(laser[i] != NULL && laser[i]->getPositionX() == (pFalconx->getFalconXposX() + 5) && laser[i]->getPositionY() == (pFalconx->getFalconXposY() - 4))){
				laser[i]->removeLaser();
				return true;
			}
		}
			return false;
}
bool Collision::testBombDestroyerVsFalcon(Bomb* bomb, FalconX* pFalconx) {
	int bombX = bomb->getBombposX();
	int falconX = pFalconx->getFalconXposX();

	if (bombX >= falconX && bombX <= (falconX + 4)) {
		if (bomb->getBombposY() == pFalconx->getFalconXposY()) {
			return true;
		}
	}
	return false;
}
bool Collision::testLaserFalconVsDestroyer(FalconX* pFalconx, Destroyer* destroyer) {
	if (destroyer != NULL) {
		for (int i = 0; i < pFalconx->getNoElementLaserLeft(); i++) {

			int leftLaserX = pFalconx->getPositionXLaserLeft(i);
			int leftLaserY = pFalconx->getPositionYLaserLeft(i);

			int destroyerX = destroyer->coord.getPositionX();
			int destroyerY = destroyer->coord.getPositionY();

			if (leftLaserX == (destroyerX - 1) && leftLaserY == (destroyerY + 3)) {
				return true;
			}
			else if (leftLaserX == (destroyerX) && leftLaserY == (destroyerY + 2)) {
				return true;
			}
			else if (leftLaserX == (destroyerX + 1) && leftLaserY == (destroyerY + 2)) {
				return true;
			}
			else if (leftLaserX == (destroyerX + 2) && leftLaserY == (destroyerY + 2)) {
				return true;
			}
			else if (leftLaserX == (destroyerX + 3) && leftLaserY == (destroyerY + 3)) {
				return true;
			}
		}

		for (int i = 0; i < pFalconx->getNoElementLaserRight(); i++) {

			int rightLaserX = pFalconx->getPositionXLaserRight(i);
			int rightLaserY = pFalconx->getPositionYLaserRight(i);

			int destroyerX = destroyer->coord.getPositionX();
			int destroyerY = destroyer->coord.getPositionY();

			if (rightLaserX == (destroyerX - 1) && rightLaserY == (destroyerY + 3)) {
				return true;
			}
			else if (rightLaserX == (destroyerX) && rightLaserY == (destroyerY + 2)) {
				return true;
			}
			else if (rightLaserX == (destroyerX + 1) && rightLaserY == (destroyerY + 2)) {
				return true;
			}
			else if (rightLaserX == (destroyerX + 2) && rightLaserY == (destroyerY + 2)) {
				return true;
			}
			else if (rightLaserX == (destroyerX + 3) && rightLaserY == (destroyerY + 3)) {
				return true;
			}
		}
	}

	return false;
}