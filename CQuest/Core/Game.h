#pragma once

#include "..\Menus\Menu.h"
#include <map>

class Game
{
public:
	Game();
	~Game();

	// List of possible menus.
	//enum MENUS { MAIN, CHARACTER_SELECT, GAME_OVER, NONE };

	const		void									SetGameOver(bool poop)									{ gameOver = poop; }
	const		void									EndGame();
	const		bool									IsGameOver()											{ return gameOver; }
	const		void									AddMenu(Menu::MENUS menuName, Menu* menu);
	const		std::map<Menu::MENUS, Menu*>			GetMenus()								const			{ return menus; }
	const		Menu*									GetMenu(Menu::MENUS menuName)			const;
	const		void									SetActiveMenu(Menu::MENUS menu)							{ activeMenu = menu; }
	const		Menu*									GetActiveMenu();
				bool									CheckActiveMenu()						const;
	const		void									ChangeMenu(Menu::MENUS menu);
private:
	// Game over status.
	bool gameOver;

	// Store of all menus.
	std::map<Menu::MENUS, Menu*> menus;

	// Currently active menu.
	Menu::MENUS activeMenu = Menu::MENUS::NONE;
};

