#include "Screen.h"
#include "RockUtiles.h"

Screen::Screen() {
	this->width = 0;
	this->height = 0;
	this->size = 0;
	this->screenBuffer = 0;
}

Screen::~Screen() {
	delete[] screenBuffer;
}

void Screen::setupSize(int width, int height) {
	this->width = width; // we are copying the values to be used in other screen functions
	this->height = height;
	this->size = width * height;

	this->screenBuffer = new char[this->size];

	setDimensionFenetre(0, 0, width, height);
	curseurVisible(false);
}

void Screen::clearScreen() {
	for (int i = 0; i < size; i++) {
		screenBuffer[i] = 0;
	}
}
void Screen::drawBorder(int color) {
	cadre(0, 0, width - 4, height - 4, color);
}