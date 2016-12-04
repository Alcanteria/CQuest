#include "stdafx.h"
#include "MainMenu.h"
#include <iostream>
#include "..\Core\Game.h"


MainMenu::MainMenu(Game& gameReference) : Menu(gameReference)
{
	welcomeMessage = "**********Welcome To C Quest**********";

	AddOptionKey("1", "Start New Game.");
	AddOptionKey("2", Menu::EXIT);
}

MainMenu::~MainMenu()
{
Debug::Print("MainMenu() Destructor.", Debug::PRIORITY::LOW);
}

// Use this method to take the input key pressed by the user. It will figure out what to do with the key input.
void MainMenu::ValidateKeyPressed(std::string key)
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
void MainMenu::ProcessOptionKeyPress(std::string key)
{
	if (key == "1")
		GetGame().ChangeGameMenu(Menu::MENUS::STORY_SELECT);

	if (key == "2")
		GetGame().EndGame();
}