#include "stdafx.h"
#include "Game.h"
#include "..\Menus\MainMenu.h"
#include "..\Menus\GameOverMenu.h"
#include "..\Menus\CharacterSelectMenu.h"
#include <iostream>

//#define DEBUG_MODE = 1

Game::Game()
{
	MainMenu* mainMenu = new MainMenu(this);
	AddMenu(Menu::MENUS::MAIN, mainMenu);

	GameOverMenu* gameOverMenu = new GameOverMenu(this);
	AddMenu(Menu::MENUS::GAME_OVER, gameOverMenu);

	CharacterSelectMenu* characterSelectMenu = new CharacterSelectMenu(this);
	AddMenu(Menu::MENUS::CHARACTER_SELECT, characterSelectMenu);

	SetActiveMenu(Menu::MENUS::MAIN);
	SetPreviousMenu(Menu::MENUS::MAIN);
}


Game::~Game()
{
	delete menus.at(Menu::MENUS::MAIN);
	delete menus.at(Menu::MENUS::CHARACTER_SELECT);
	delete menus.at(Menu::MENUS::GAME_OVER);

#if defined(DEBUG_MODE)
	std::cout << "Game Destructor." << std::endl;
#endif
}

// Add a new menu to the store of possibe game menus.
const void Game::AddMenu(Menu::MENUS menuName, Menu* menu)
{
	menus.insert(std::make_pair(menuName, menu));
}

// Retrieve the specified menu.
const Menu* Game::GetMenu(Menu::MENUS menu) const
{
	return menus.at(menu);
}

// Retrieve the currently active menu.
const Menu* Game::GetActiveMenu() const
{
	return menus.at(activeMenu);
}

// Retrieve the menu viewed previous to the current one.
const Menu* Game::GetPreviousMenu() const
{
	return menus.at(previousMenu);
}

// Check to see if the active menu is a real menu, or the indicator that the game is at an end.
bool Game::CheckActiveMenu() const
{
	if (activeMenu != Menu::MENUS::GAME_OVER)
		return true;
	else
		return false;
}

// Ends the current game. This ends the game loop so the main() can properly clean up before exiting the program.
const void Game::EndGame()
{
	Menu::PrintGap(2);
	std::cout << "##### GAME OVER #####" << std::endl;
	SetGameOver(true);
}

// Change the active menu to the passes menu enum.
const void Game::ChangeMenu(Menu::MENUS menu)
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
	menus.at(menu)->ShowWelcomeMessage();
}

const void Game::NameCharacter(std::string name)
{
	player.SetCharacterName(name);
}