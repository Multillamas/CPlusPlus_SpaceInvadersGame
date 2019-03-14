#ifndef VAISSEAU_H
#define VAISSEAU_H
#include "Laser.h"
#include "Coord.h"
#include "SpaceSound.h"

class Vaisseau
{

protected:
	void removeVaisseau() const;
	void putVaisseau() const;

public:
	Coord coord;
	Vaisseau();		
	void modifierPosition(char);
};

#endif