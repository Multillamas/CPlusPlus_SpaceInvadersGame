#include "Keyboard.h"
#include <conio.h>
#include <ctype.h>

int Keyboard::recupererTouche()
{
	if (_kbhit() != 0)
	{
		return tolower(_getch());
	}
	return -1;
}

