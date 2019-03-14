#include "MainMenu.h"
#include "Game.h"
#include "Coord.h"
#include "Keyboard.h"
#include "RockUtiles.h"
#include <iostream>
using namespace std;

void MainMenu::start(Screen& screen) {
	system("cls");
	spaceSound.mainMenuSound();
	screen.drawBorder(2);
	
	Coord::gotoXY(15, 3);
	std::cout<<"     .d8888b.                                      "; Coord::gotoXY(15, 4);
	std::cout<<"    d88P  Y88b                                     "; Coord::gotoXY(15, 5);
	std::cout<<"    Y88b.                                          "; Coord::gotoXY(15, 6);
	std::cout<<"    `Y888b.   88888b.   8888b.   .d8888b .d88b.    "; Coord::gotoXY(15, 7);
	std::cout<<"       `Y88b. 888 `88b     `88b d88P`   d8P  Y8b   "; Coord::gotoXY(15, 8);
	std::cout<<"        `888  888  888 .d888888 888     88888888   "; Coord::gotoXY(15, 9);
	std::cout<<"        Y88b  d88  888 d88P 888  888    .Y8b.      "; Coord::gotoXY(15, 10);
	std::cout<<"    `Y8888P`  88888P`  `Y888888  `Y8888P `Y8888    "; Coord::gotoXY(15, 11);
	std::cout<<"              888	                               "; Coord::gotoXY(15, 12);
	std::cout<<"              888	                               "; Coord::gotoXY(15, 13);
	std::cout<<"              888	                               ";
					
	Coord::gotoXY(8, 15);
	std::cout << "88888888                                 888                        8888888 8888888";Coord::gotoXY(8, 16);
	std::cout << "  888                                    888                          888     888";Coord::gotoXY(8, 17);
	std::cout << "  888                                    888                          888     888";Coord::gotoXY(8, 18);
	std::cout << "  888    88888b.  888  888  8888b.   .d88888  .d88b.   888d888        888     888";Coord::gotoXY(8, 19);
	std::cout << "  888    888 `88b 888  888    `88b  d88` 888 d8P  Y8b  888P`          888     888";Coord::gotoXY(8, 20);
	std::cout << "  888    888  888 Y88  88P .d888888 888  888 88888888  888            888     888";Coord::gotoXY(8, 21);
	std::cout << "  888    888  888  Y8bd8P  888  888  Y88b888 Y8b.      888            888     888";Coord::gotoXY(8, 22);
	std::cout << "8888888  888  888   Y88P  `Y888888   `Y88888  `Y8888   888          8888888 8888888";



	Coord::gotoXY(40, 30);
	cout << "MENU PRINCIPAL :";
	Coord::gotoXY(40, 32);
	cout << "1 -> pour choisir niveaux";
	Coord::gotoXY(40, 34);
	cout << "X -> pour sortir";
}

int MainMenu::run() {
	
	int key = Keyboard::recupererTouche();

	if (key == 'x') {
		spaceSound.selectMenuSound();
		return Game::QUIT_GAME;
	}
	else if (key == '1') {
		spaceSound.selectMenuSound();
		return Game::DIFFICULTY_MENU_STATE;
	}

	return Game::MAIN_MENU_STATE;
}
