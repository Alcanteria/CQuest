#pragma once

#include "..\Menus\Menu.h"
#include <map>
#include "..\Characters\CharacterClass.h"
#include "Timer.h"
#include "..\Setting\Story.h"
#include "Dice.h"
#include "SaveData.h"
#include "Debugger.h"

class Game
{
public:
	Game();
	~Game();

	const		void									AddMenu(Menu::MENUS menuName, Menu* menu);
				bool									CheckActiveMenu()								const;
	const		void									ChangeGameMenu(Menu::MENUS menu);
	const		void									CreateNewCharacter(CharacterClass* character);
	const		void									EndGame();
	const		Menu*									GetActiveMenu()									const;
	const		Debugger&								GetDebugger()									const			{ return *debugger; }
				Dice&									GetDice()										const			{ return *dice; }
	const		CharacterClass*							GetCharacter()									const			{ return playerCharacter; }
	const		std::string								GetCharacterName()								const			{ return characterName; }
	const		Menu*									GetMenu(Menu::MENUS menuName)					const;
	const		std::map<Menu::MENUS, Menu*>			GetMenus()										const			{ return menus; }
	const		Menu*									GetPreviousMenu()								const;
	const		std::string								GetRandomGameIntro();
	const		SaveData&								GetSaveData()									const			{ return *saveData; }
	const		Story&									GetStory()										const			{ return *story; }
				Timer&									GetTimer()														{ return *timer; }	
	const		bool									IsGameOver()													{ return gameOver; }
	const		void									NameCharacter(std::string name);
	const		void									SetGameOver(bool poop)											{ gameOver = poop; }
	const		void									SetActiveMenu(Menu::MENUS menu)									{ activeMenu = menu; }
	const		void									SetPreviousMenu(Menu::MENUS menu)								{ previousMenu = menu; }

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

	// Game over status.
	bool gameOver;

	// Store of all menus.
	std::map<Menu::MENUS, Menu*> menus;

	// The class that the player selects.
	CharacterClass* playerCharacter;

	// Object for reading/writing save data.
	SaveData* saveData;

	// Object that stores story text.
	Story* story;

	// Class used to track time and function as a stopwatch.
	Timer* timer;
};

