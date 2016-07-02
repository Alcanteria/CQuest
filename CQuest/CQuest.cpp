// CQuest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Menus\Menu.h"


int _tmain(int argc, _TCHAR* argv[])
{
	Menu * pMenu = new Menu();

	pMenu->ShowWelcomeMessage();
	pMenu->AddOptionKey('A');

	bool test = false;
	char input;

	while (!test)
	{
		std::cout << "Press a key to test if it is in the option key vector." << std::endl;
		std::cin >> input;

		if (pMenu->IsOptionKeyPresent(input))
		{
			test = true;
			std::cout << "Key found!" << std::endl;
		}
	}

	delete pMenu;
	pMenu = 0;

	return 0;
}

