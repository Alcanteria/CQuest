#include "stdafx.h"
#include "Menu.h"
#include <iostream>

Menu::Menu()
{
	SetWelcomeMessage("Menu Class.");
}


Menu::~Menu()
{
}

void Menu::ShowWelcomeMessage() const
{
	std::cout << GetWelcomeMessage() << std::endl;
}
