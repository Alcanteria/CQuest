// CQuest.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include <iostream>
#include "Core\Game.h"

int _tmain(int argc, _TCHAR* argv[])
{
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
	game = 0;

	return 0;
}

