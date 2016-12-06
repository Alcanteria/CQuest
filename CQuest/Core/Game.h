#pragma once

#include "stdafx.h"
#include "..\Menus\Menu.h"
#include <map>
#include "..\Characters\CharacterClass.h"
#include "Timer.h"
#include "..\Setting\Story.h"
#include "SaveData.h"
#include "Graphics\Logo.h"
#include "Setting\DM.h"
#include <random>

class Game
{
public:
	Game();
	~Game();

				void									AddMenu(Menu::MENUS menuName, Menu* menu);
				bool									CheckActiveMenu()								const;
				void									ChangeGameMenu(Menu::MENUS menu);
				void									CreateNewCharacter(CharacterClass* character);
				void									EndGame();
				Menu*									GetActiveMenu();
	const		CharacterClass*							GetCharacter()									const			{ return playerCharacter; }
	const		std::string								GetCharacterName()								const			{ return characterName; }
				DM&										GetDM()															{ return *dm; }
				Menu*									GetMenu(Menu::MENUS menuName)					const;
	const		std::map<Menu::MENUS, Menu*>			GetMenus()										const			{ return menus; }
	const		Menu*									GetPreviousMenu()								const;
				SaveData&								GetSaveData()													{ return *saveData; }
				Timer&									GetTimer()														{ return *timer; }
				void									GoBackToPreviousMenu();
	const		bool									IsGameOver()													{ return gameOver; }
				void									NameCharacter(std::string name);
				void									SetGameOver(bool poop)											{ gameOver = poop; }
				void									SetActiveMenu(Menu::MENUS menu)									{ activeMenu = menu; }
				void									SetPreviousMenu(Menu::MENUS menu)								{ previousMenu = menu; }

	// Currently active menu.
	Menu::MENUS activeMenu = Menu::MENUS::NONE;

	// The menu that was open previous to the current menu.
	Menu::MENUS previousMenu = Menu::MENUS::NONE;

private:
	// The name of the player character.
	std::string characterName;

	// Class that handles all of the story and game progression information.
	DM* dm;

	// Game over status.
	bool gameOver;

	// Class used to load and display the logo.
	Logo* logo;

	// Store of all menus.
	std::map<Menu::MENUS, Menu*> menus;

	// The class that the player selects.
	CharacterClass* playerCharacter;

	// Object for reading/writing save data.
	SaveData* saveData;

	// Class used to track time and function as a stopwatch.
	Timer* timer;
};

/*	This is used to print debug messages to screen. */
namespace Debug
{

	// Allows different levels of message priority so some can be filtered out during testing.
	enum PRIORITY { LOW = 0, MID = 1, TOP = 2 };

	const	static PRIORITY DEBUG_MODE = Debug::PRIORITY::MID;

			void	Print(std::string message, Debug::PRIORITY level);
}

/*	This is used to generate random numbers in a simple interface. */
namespace Dice
{
	static std::mt19937 randomNumberGenerator;

	const	int		Roll(int lowest, int highest);
}