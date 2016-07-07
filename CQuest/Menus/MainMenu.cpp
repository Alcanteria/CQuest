#include "stdafx.h"
#include "MainMenu.h"
#include <iostream>
#include "..\Core\Game.h"


MainMenu::MainMenu(Game* game) : Menu(game)
{
	welcomeMessage = "**********Welcome To CQuest.**********";

	AddOptionKey('1', "Start New Game.");
	AddOptionKey('2', "Exit.");
}

MainMenu::~MainMenu()
{

}

// Use this method to take the input key pressed by the user. It will figure out what to do with the key input.
void MainMenu::CheckKeyPressed(char key) const
{
	if (IsOptionKeyPresent(key))
	{
		ProcessOptionKeyPress(key);
	}
	else
	{
		std::cout << "Not a valid option. Please try again." << std::endl;
	}
}

// Takes a key input that has been verified to be a legal option in the menu and performs the corresponding task.
void MainMenu::ProcessOptionKeyPress(char key) const
{
	switch (key)
	{
	case '1':
		std::cout << "Game Started." << std::endl;
		break;
	case '2':
	{
		game->EndGame();
		break;
	}		
	default:
		break;
	}
}