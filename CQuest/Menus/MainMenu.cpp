#include "stdafx.h"
#include "MainMenu.h"
#include <iostream>
#include "..\Core\Game.h"


MainMenu::MainMenu(Game* game) : Menu(game)
{
	welcomeMessage = "**********Welcome To CQuest.**********";

	AddOptionKey("1", "Start New Game.");
	AddOptionKey("2", Menu::EXIT);
}

MainMenu::~MainMenu()
{

}

// Use this method to take the input key pressed by the user. It will figure out what to do with the key input.
void MainMenu::CheckKeyPressed(std::string key) const
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
void MainMenu::ProcessOptionKeyPress(std::string key) const
{
	if (key == "1")
		game->ChangeMenu(Menu::MENUS::CHARACTER_SELECT);

	if (key == "2")
		game->EndGame();
}