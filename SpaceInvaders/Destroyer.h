#pragma once
#include "ExtraTerrestre.h"

class Destroyer : public ExtraTerrestre
{
private:
	int viesDestroyer;

public:
	Destroyer(int type, int valeur);
	~Destroyer();

	void setDestroyerPos(int x, int y);
	void putDestroyer();
	void removeDestroyer();
	void deplacerDestroyer();
	int getDestroyerPosX();
	int getDestroyerPosY();
	void KillDestroyer(); 
	void hitByFalcon();
	bool isAlive;
	
};

