// CQuest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Menus\Menu.h"


int _tmain(int argc, _TCHAR* argv[])
{
	Menu * pMenu = new Menu();

	pMenu->ShowWelcomeMessage();

	delete pMenu;
	pMenu = 0;

	return 0;
}

