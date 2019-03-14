#include "DifficultyMenu.h"
#include "Game.h"
#include "Coord.h"
#include "Keyboard.h"
#include <iostream>
#include "RockUtiles.h"
using namespace std;

void DifficultyMenu::start() {
	system("cls");
	spaceSound.creepySound();
	Coord::gotoXY(10, 10);

	std::cout << "_                      _______                      _ "; Coord::gotoXY(10, 11);
	std::cout<<"                   _dMMMb._.adOOOOOOOOOba._, dMMMb_                       "; Coord::gotoXY(10, 12);
	std::cout<<"	dP'  ~YMMb            dOOOOOOOOOOOOOOOb            aMMP~  `Yb "; Coord::gotoXY(10, 13);
	std::cout<<"	V      ~`Mb       dOOOOOOOOOOOOOOOOOb          dM`~V "; Coord::gotoXY(10, 14);
	std::cout<<"             `Mb.            dOOOOOOOOOOOOOOOOOOOb, dM' "; Coord::gotoXY(10, 15);
	std::cout<<"               `YMb._ | OOOOOOOOOOOOOOOOOOOOO | _, dMP' "; Coord::gotoXY(10, 16);
	std::cout<<"               `YMMM| OP'~`YOOOOOOOOOOOP`~`YO |MMMP'      __ "; Coord::gotoXY(10, 17);
	std::cout<<"	, dMMMb.     ~~' OO     `YOOOOOP'     OO `~~, dMMMb. "; Coord::gotoXY(10, 18);
	std::cout<<"	_, dP~`YMba_     OOb      `OOO'      dOO      _aMMP'  ~Yb._ "; Coord::gotoXY(10, 19);
	std::cout<<"	`YMMMM\`OOOo     OOO       oOOO'       /MMMMP' "; Coord::gotoXY(10, 20);
	std::cout<<"	, aa.     `~YMMb `OOOb._, dOOOb._, dOOO'dMMP~', aa. "; Coord::gotoXY(10, 21);
	std::cout<<"	, dMYYMba._         `OOOOOOOOOOOOOOOOO'          _, adMYYMb. "; Coord::gotoXY(10, 22);
	std::cout<<"	, MP'   `YMMba._      OOOOOOOOOOOOOOOOO       _,adMMP'   `YM. "; Coord::gotoXY(10, 23);
	std::cout<<"	MP'        ~YMMMba._ YOOOOPVVVVVYOOOOP  _,adMMMMP~       `YM "; Coord::gotoXY(10, 24);
	std::cout<<"	YMb           ~YMMMM\`OOOOI`````IOOOOO'/MMMMP~dMP "; Coord::gotoXY(10, 25);
	std::cout<<"	`Mb.           `YMMMb`OOOI,, , ,IOOOO'dMMMP', dM' "; Coord::gotoXY(10, 26);
	std::cout<<"	`'                  `OObNNNNNdOO'                   `' "; Coord::gotoXY(10, 27);
	std::cout<<"	`~OOOOO~'  "; 

	Coord::gotoXY(30, 35);
	cout << "CHOISIR NIVEAU :";
	Coord::gotoXY(30, 37);
	cout << "1 -> facile";
	Coord::gotoXY(30, 39);
	cout << "2 -> moyen";
	Coord::gotoXY(30, 41);
	cout << "3 -> difficile";
	Coord::gotoXY(30, 43);
	cout << "X -> pour retourner au menu principal";
}

int DifficultyMenu::run() {

	int key = Keyboard::recupererTouche();

	if (key == 'x') {
		spaceSound.selectMenuSound();
		return Game::MAIN_MENU_STATE;
	}
	else if (key == '1') {
		setLevel(1);
		spaceSound.selectMenuSound();
		return Game::SPACE_INVADERS_STATE;
	}
	else if (key == '2') {
		setLevel(2);
		spaceSound.mainMenuSound();
		return Game::SPACE_INVADERS_STATE;
	}
	else if (key == '3') {
		setLevel(3);
		spaceSound.mainMenuSound();
		return Game::SPACE_INVADERS_STATE;
	}

	return Game::DIFFICULTY_MENU_STATE;
}
void DifficultyMenu::setLevel(int level){
	this->level = level;
}
int DifficultyMenu::getLevel() {
	return this->level;
}
