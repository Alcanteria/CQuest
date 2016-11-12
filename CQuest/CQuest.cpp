// CQuest.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include <iostream>
#include "Core\Game.h"
#include <Windows.h>

int _tmain(int argc, _TCHAR* argv[])
{
	// Had to make the console window width bigger so the logo would fit.
	System::Console::WindowWidth = System::Console::LargestWindowWidth * .75;
	Game* game = new Game();

	char input;

	game->GetActiveMenu()->ShowWelcomeMessage();

	while (!game->IsGameOver())
	{
		game->GetActiveMenu()->ShowAllOptions();

		std::cin >> input;

		std::string stringInput;
		stringInput = input;

		game->GetActiveMenu()->ValidateKeyPressed(stringInput);
	}

	delete game;
	game = nullptr;

	return 0;
}

