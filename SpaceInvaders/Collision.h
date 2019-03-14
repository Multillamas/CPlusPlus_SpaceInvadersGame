#pragma once
#include "FalconX.h"
#include "Fighter.h"
#include "Destroyer.h"
#include "Bomb.h"
#include "SpaceSound.h"


class Collision {
	SpaceSound spaceSound;
public:
	bool testFalconVsFighter(Fighter* tab[], FalconX* pFalconx, int* nbFighter);
	void testLaserFalconVsFighter(FalconX* pFalconx, Fighter* tab[], int* nbFighter );
	bool testLaserFighterVsFalcon(FalconX* pFalconx, LaserFighter* laser[], int nbLaser);
	bool testBombDestroyerVsFalcon(Bomb* bomb, FalconX* pFalconx);
	bool testLaserFalconVsDestroyer(FalconX* pFalconx, Destroyer* destroyer);

};