#include "stdafx.h"
#include "Game.h"
#include "..\Menus\MainMenu.h"
#include "..\Menus\GameOverMenu.h"
#include "..\Menus\CharacterSelectMenu.h"
#include <iostream>

Game::Game()
{
	MainMenu* mainMenu = new MainMenu(*this);
	AddMenu(Menu::MENUS::MAIN, mainMenu);

	GameOverMenu* gameOverMenu = new GameOverMenu(*this);
	AddMenu(Menu::MENUS::GAME_OVER, gameOverMenu);

	CharacterSelectMenu* characterSelectMenu = new CharacterSelectMenu(*this);
	AddMenu(Menu::MENUS::CHARACTER_SELECT, characterSelectMenu);

	SetActiveMenu(Menu::MENUS::MAIN);
	SetPreviousMenu(Menu::MENUS::MAIN);

	timer = new Timer();
	story = new Story(*this);
	dice = new Dice(*this);
	saveData = new SaveData(*this);
	debugger = new Debugger();
	logo = new Logo(*this);
	dm = new DM(*this);

	saveData->VerifySaveData();

	dm->Initialize();
	logo->ShowLogo();
	timer->Wait(2);
	
	timer->PrintFastGap();
	std::cout << story->GetRandomIntro() << std::endl;
	timer->Wait(4);
	timer->PrintFastGap();
}


Game::~Game()
{
	debugger->Print("Game() Destructor.");

	delete	menus.at(Menu::MENUS::MAIN);
			menus.at(Menu::MENUS::MAIN) = nullptr;
	delete	menus.at(Menu::MENUS::CHARACTER_SELECT);
			menus.at(Menu::MENUS::CHARACTER_SELECT) = nullptr;
	delete	menus.at(Menu::MENUS::GAME_OVER);
			menus.at(Menu::MENUS::GAME_OVER) = nullptr;
	delete	timer;
			timer = nullptr;
	delete	story;
			story = nullptr;
	delete	dice;
			dice = nullptr;
	delete	saveData;
			saveData = nullptr;
	delete	debugger;
			debugger = nullptr;
	delete	logo;
			logo = nullptr;
	delete	dm;
			dm = nullptr;
}

// Add a new menu to the store of possibe game menus.
void Game::AddMenu(Menu::MENUS menuName, Menu* menu)
{
	menus.insert(std::make_pair(menuName, menu));
}

// Check to see if the active menu is a real menu, or the indicator that the game is at an end.
bool Game::CheckActiveMenu() const
{
	if (activeMenu != Menu::MENUS::GAME_OVER)
		return true;
	else
		return false;
}

// Change the active menu to the passes menu enum.
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

void Game::CreateNewCharacter(CharacterClass* character)
{
	playerCharacter = character;
}

// Ends the current game. This ends the game loop so the main() can properly clean up before exiting the program.
void Game::EndGame()
{
	GetTimer().PrintFastGap();
	std::cout << "##### GAME OVER #####" << std::endl;
	SetGameOver(true);
}

// Retrieve the currently active menu.
const Menu* Game::GetActiveMenu() const
{
	return menus.at(activeMenu);
}

// Retrieve the specified menu.
const Menu* Game::GetMenu(Menu::MENUS menu) const
{
	return menus.at(menu);
}

// Retrieve the menu viewed previous to the current one.
const Menu* Game::GetPreviousMenu() const
{
	return menus.at(previousMenu);
}

void Game::NameCharacter(std::string name)
{
	characterName = name;
}