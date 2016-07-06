#include "stdafx.h"
#include "Game.h"
#include "..\Menus\MainMenu.h"
#include "..\Menus\GameOverMenu.h"

Game::Game()
{
	MainMenu* mainMenu = new MainMenu(this);
	AddMenu(MENUS::MAIN, mainMenu);

	GameOverMenu* gameOverMenu = new GameOverMenu(this);
	AddMenu(MENUS::GAME_OVER, gameOverMenu);

	SetActiveMenu(MENUS::MAIN);
}


Game::~Game()
{
	delete menus.at(MENUS::MAIN);
	delete menus.at(MENUS::GAME_OVER);
}

// Add a new menu to the store of possibe game menus.
const void Game::AddMenu(MENUS menuName, Menu* menu)
{
	menus.insert(std::make_pair(menuName, menu));
}

// Retrieve the specified menu.
const Menu* Game::GetMenu(MENUS menu) const
{
	return menus.at(menu);
}

// Retrieve the currently active menu.
const Menu* Game::GetActiveMenu() const
{
	return menus.at(activeMenu);
}

// Check to see if the active menu is a real menu, or the indicator that the game is at an end.
bool Game::CheckActiveMenu() const
{
	if (activeMenu != MENUS::GAME_OVER)
		return true;
	else
		return false;
}