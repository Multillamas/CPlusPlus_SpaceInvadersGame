#pragma once
#include "Laser.h"
class FalconLaser : public Laser{
public:
	void startLaserLeft(int x, int y);
	void startLaserRight(int x,int y);
};