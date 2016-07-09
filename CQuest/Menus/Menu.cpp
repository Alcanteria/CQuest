#include <stdafx.h>
#include "Menu.h"
#include <iostream>
#include <algorithm>

Menu::Menu(Game* game) : game(game)
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

// Search for the passed key press value in the map store.
const bool Menu::IsOptionKeyPresent(std::string key) const
{
	std::map<std::string, std::string>::const_iterator iterator;
	iterator = optionKeys.find(key);

	if (iterator != optionKeys.end())
		return true;
	else
		return false;
}

// Add the passed string description at the passed character key location.
void Menu::AddOptionKey(std::string key, std::string description)
{
	optionKeys.insert(std::make_pair(key, description));
}

// Cycles through the option key map and prints every item to the console.
void Menu::ShowAllOptions() const
{
	for (auto const &item : optionKeys)
	{
		std::cout << item.first << ".     " << item.second << std::endl;
	}

	std::cout << "-----Please enter a number from the available options.-----" << std::endl;
}

// See if the key pressed is one of the available options.
void Menu::CheckKeyPressed(std::string key) const
{
	if (IsOptionKeyPresent(key))
		std::cout << "Valid Option." << std::endl;
	else
		std::cout << "-----Not a valid choice. Please try again.-----" << std::endl;
}

// Takes a key input that has been verified to be a legal option in the menu and performs the corresponding task.
void Menu::ProcessOptionKeyPress(std::string key) const
{
	switch (key[0])
	{
	case '1':
		std::cout << "Default Menu Function." << std::endl;
		break;
	case '2':
		std::cout << "DEFAULT Game Over DEFAULT." << std::endl;

	default:
		break;
	}
}