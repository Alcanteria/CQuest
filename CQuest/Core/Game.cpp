#include "stdafx.h"
#include "Game.h"
#include "..\Menus\MainMenu.h"


Game::Game()
{
	MainMenu mainMenu;
	AddMenu(MENUS::MAIN, mainMenu);

	SetActiveMenu(MENUS::MAIN);
}


Game::~Game()
{
}

// Add a new menu to the store of possibe game menus.
const void Game::AddMenu(MENUS menuName, Menu menu)
{
	menus.insert(std::make_pair(menuName, menu));
}

// Retrieve the specified menu.
const Menu Game::GetMenu(MENUS menu) const
{
	return menus.at(menu);
}

// Retrieve the currently active menu.
const Menu Game::GetActiveMenu() const
{
	return menus.at(activeMenu);
}