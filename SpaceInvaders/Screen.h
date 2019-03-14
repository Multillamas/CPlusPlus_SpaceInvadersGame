#pragma once

class Screen
{
public:
	Screen();
	~Screen();
	void setupSize(int width, int height);
	void clearScreen();
	void drawBorder(int color);

private:
	int width;
	int height;
	int size;
	char* screenBuffer;
};
