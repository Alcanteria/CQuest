#include <stdafx.h>
#include "Menu.h"
#include <iostream>
#include <algorithm>

Menu::Menu()
{
	SetWelcomeMessage("Base Menu Class.");
}


Menu::~Menu()
{
}

// Print the default welcome message to the console.
void Menu::ShowWelcomeMessage() const
{
	std::cout << GetWelcomeMessage() << std::endl;
}

// Search for the passed key value in the map store.
const bool Menu::IsOptionKeyPresent(char key) const
{
	std::map<char, std::string>::const_iterator iterator;
	iterator = optionKeys.find(key);

	if (iterator != optionKeys.end())
		return true;
	else
		return false;
}

// Add the passed string description at the passed character key location.
void Menu::AddOptionKey(char key, std::string description)
{
	optionKeys.insert(std::make_pair(key, description));
}

// Cycles through the option key map and prints every item to the console.
void Menu::ShowAllOptions() const
{
	for (auto const &item : optionKeys)
	{
		std::cout << item.first << "     " << item.second << std::endl;
	}
}
