#pragma once
#include "Martien.h"
#include "LaserFighter.h"
#include<iostream>

class Fighter : public Martien {
	
public:
	Fighter(int, int);
	void genererPosAleatoire();
	void deplacerBas();
	int getPositionX();
	int getPositionY();
};