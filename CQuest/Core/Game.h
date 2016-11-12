#pragma once

#include "..\Menus\Menu.h"
#include <map>
#include "..\Characters\CharacterClass.h"
#include "Timer.h"
#include "..\Setting\Story.h"
#include "Dice.h"
#include "SaveData.h"
#include "Debugger.h"
#include "Graphics\Logo.h"
#include "Setting\DM.h"

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
	const		Menu*									GetActiveMenu()									const;
	const		CharacterClass*							GetCharacter()									const			{ return playerCharacter; }
	const		std::string								GetCharacterName()								const			{ return characterName; }
	const		Debugger&								GetDebugger()									const			{ return *debugger; }
				Dice&									GetDice()										const			{ return *dice; }
	const		DM&										GetDM()											const			{ return *dm; }
	const		Menu*									GetMenu(Menu::MENUS menuName)					const;
	const		std::map<Menu::MENUS, Menu*>			GetMenus()										const			{ return menus; }
	const		Menu*									GetPreviousMenu()								const;
	const		SaveData&								GetSaveData()									const			{ return *saveData; }
				Timer&									GetTimer()														{ return *timer; }	
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

	// Object that handles debug status and reporting.
	Debugger* debugger;

	// Object for random number generation.
	Dice* dice;

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

