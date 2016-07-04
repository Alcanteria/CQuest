#pragma once

#include "..\Menus\Menu.h"
#include <map>

class Game
{
public:
	Game();
	~Game();

	// List of possible menus.
	enum MENUS { MAIN };

	const		void									SetGameOver(bool poop)									{ gameOver = poop; }
	const		bool									IsGameOver()											{ return gameOver; }
	const		void									AddMenu(MENUS menuName, Menu menu);
	const		std::map<MENUS, Menu>					GetMenus()								const			{ return menus; }
	const		Menu									GetMenu(MENUS menuName)					const;
	const		void									SetActiveMenu(MENUS menu)								{ activeMenu = menu; }
	const		Menu									GetActiveMenu()							const;
private:
	// Game over status.
	bool gameOver;

	// Store of all menus.
	std::map<MENUS, Menu> menus;

	// Currently active menu.
	MENUS activeMenu;
};

