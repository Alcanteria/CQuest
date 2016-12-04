#include "stdafx.h"
#include "Game.h"
#include "..\Menus\MainMenu.h"
#include "..\Menus\GameOverMenu.h"
#include "..\Menus\StorySelectMenu.h"
#include <iostream>

Game::Game()
{
	// Instantiate parts.
	timer = new Timer();
	dice = new Dice(*this);
	dm = new DM(*this);
	saveData = new SaveData(*this);
	logo = new Logo(*this);

	saveData->VerifySaveData();

	dm->Initialize();


	// Create menus.
	AddMenu(Menu::MENUS::MAIN, new MainMenu(*this));
	AddMenu(Menu::MENUS::GAME_OVER, new GameOverMenu(*this));
	AddMenu(Menu::MENUS::STORY_SELECT, new StorySelectMenu(*this));
	
	/* TESTING STORY SELECT MENU ***********************************/
	GetMenu(Menu::MENUS::STORY_SELECT)->Initialize();

	SetActiveMenu(Menu::MENUS::MAIN);
	SetPreviousMenu(Menu::MENUS::MAIN);

	logo->ShowLogo();
	timer->Wait(2);
	
	timer->PrintFastGap();
}


Game::~Game()
{
Debug::Print("Game() Destructor.", Debug::PRIORITY::LOW);

	delete	menus.at(Menu::MENUS::MAIN);
			menus.at(Menu::MENUS::MAIN) = nullptr;
	delete	menus.at(Menu::MENUS::GAME_OVER);
			menus.at(Menu::MENUS::GAME_OVER) = nullptr;
	delete	timer;
			timer = nullptr;
	delete	dice;
			dice = nullptr;
	delete	saveData;
			saveData = nullptr;
	delete	logo;
			logo = nullptr;
	delete	dm;
			dm = nullptr;
}

/* 
****Add a new menu to the store of possibe game menus.
*/
void Game::AddMenu(Menu::MENUS menuName, Menu* menu)
{
	menus.insert(std::make_pair(menuName, menu));
}

/* 
****Check to see if the active menu is a real menu, or the indicator that the game is at an end.
*/
bool Game::CheckActiveMenu() const
{
	if (activeMenu != Menu::MENUS::GAME_OVER)
		return true;
	else
		return false;
}

/* 
****Change the active menu to the passes menu enum.
*/
void Game::ChangeGameMenu(Menu::MENUS menu)
{
	// Make sure the current menu isn't empty, which should indicate that the game has just loaded.
	if (activeMenu != Menu::MENUS::NONE)
	{
		// Toggle the active status boolean.
		menus.at(menu)->SetActiveStatus(false);

		// Make the current menu the previous menu (so we can go "back" from the next menu, if need be.)
		SetPreviousMenu(activeMenu);
	}

	// Change the current menu to the passed value, toggle the active boolean in the menu, and show its welcome message.
	SetActiveMenu(menu);
	menus.at(menu)->SetActiveStatus(true);

	// Printed out a series of lines to make output text easier to read.
	timer->PrintFastGap();

	menus.at(menu)->ShowWelcomeMessage();
}

/*
****
*/
void Game::CreateNewCharacter(CharacterClass* character)
{
	playerCharacter = character;
}

/* 
****Ends the current game. This ends the game loop so main() can properly clean up before exiting the program.
*/
void Game::EndGame()
{
	GetTimer().PrintFastGap();
	std::cout << "##### GAME OVER #####" << std::endl;
	SetGameOver(true);
}

/* 
****Retrieve the currently active menu.
*/
Menu* Game::GetActiveMenu()
{
	return menus.at(activeMenu);
}

/* 
****Retrieve the specified menu.
*/
Menu* Game::GetMenu(Menu::MENUS menu) const
{
	return menus.at(menu);
}

/* 
****Retrieve the menu viewed previous to the current one.
*/
const Menu* Game::GetPreviousMenu() const
{
	return menus.at(previousMenu);
}

/*
****Moves the game interface back to the previously viewed menu.
*/
void Game::GoBackToPreviousMenu()
{
	ChangeGameMenu(previousMenu);
}

/*
****
*/
void Game::NameCharacter(std::string name)
{
	characterName = name;
}

namespace Debug
{
	// Prints a message to the console if debug mode is active.
	void Print(std::string message, Debug::PRIORITY level)
	{
		if (level >= Debug::DEBUG_MODE)
		{
			std::cout << "::::NEW DEBUGGER:::::\t" << message << std::endl;
		}
	}
}