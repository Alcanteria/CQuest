#include "stdafx.h"
#include "Menu.h"
#include <iostream>
#include <algorithm>

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

const bool Menu::IsOptionKeyPresent(char key) const
{
	if (std::find(optionKeys.begin(), optionKeys.end(), key) != optionKeys.end())
		return true;
	else
		return false;
}

void Menu::AddOptionKey(char key)
{
	optionKeys.push_back(key);
}
