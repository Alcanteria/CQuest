#pragma once

#include "..\Menus\Menu.h"
#include <map>
#include "..\Characters\CharacterClass.h"
#include "Timer.h"
#include "..\Setting\Story.h"

class Game
{
public:
	Game();
	~Game();

	// List of possible menus.
	//enum MENUS { MAIN, CHARACTER_SELECT, GAME_OVER, NONE };

	const		void									SetGameOver(bool poop)											{ gameOver = poop; }
	const		void									EndGame();
	const		bool									IsGameOver()													{ return gameOver; }
	const		void									AddMenu(Menu::MENUS menuName, Menu* menu);
	const		std::map<Menu::MENUS, Menu*>			GetMenus()										const			{ return menus; }
	const		Menu*									GetMenu(Menu::MENUS menuName)					const;
	const		void									SetActiveMenu(Menu::MENUS menu)									{ activeMenu = menu; }
	const		void									SetPreviousMenu(Menu::MENUS menu)								{ previousMenu = menu; }
	const		Menu*									GetActiveMenu()									const;
	const		Menu*									GetPreviousMenu()								const;
				bool									CheckActiveMenu()								const;
	const		void									ChangeGameMenu(Menu::MENUS menu);
	const		void									NameCharacter(std::string name);
	const		CharacterClass*							GetCharacter()									const			{ return playerCharacter; }
	const		void									CreateNewCharacter(CharacterClass* character);
	const		std::string								GetCharacterName()								const			{ return characterName; }
				Timer&									GetTimer()														{ return *timer; }
	const		Story&									GetStory()										const			{ return *story; }

	// Currently active menu.
	Menu::MENUS activeMenu = Menu::MENUS::NONE;

	// The menu that was open previous to the current menu.
	Menu::MENUS previousMenu = Menu::MENUS::NONE;

private:
	// Game over status.
	bool gameOver;

	// Store of all menus.
	std::map<Menu::MENUS, Menu*> menus;

	// The class that the player selects.
	CharacterClass* playerCharacter;

	// The name of the player character.
	std::string characterName;

	// Class used to track time and function as a stopwatch.
	Timer* timer;

	// Object that stores story text.
	Story* story;
};

