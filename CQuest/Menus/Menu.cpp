#include <stdafx.h>
#include "Menu.h"
#include <iostream>
#include <algorithm>
#include "..\Core\Game.h"

Menu::Menu(Game& gameReference) : game(gameReference)
{
	SetWelcomeMessage("Base Menu Class.");
}

Menu::~Menu()
{
	GetGame().GetDebugger().Print("Menu() Destructor.");
}

// Add the passed string description at the passed character key location.
const void Menu::AddOptionKey(std::string key, std::string description)
{
	optionKeys.insert(std::make_pair(key, description));
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

// Prints a block of spaces with an arrow. Makes it easier to separate blocks of text that are printed to the command prompt.
const void Menu::PrintChunk()
{
	for (int i = 0; i < 9; i++)
		std::cout << "====================================================" << std::endl;
}

// Prints a sequence of empty spaces to create a margin between print outs. This attempts to make the text more readable.
const void Menu::PrintGap(int spaces)
{
	for (int i = 0; i < spaces; i++)
		std::cout << "" << std::endl;
}

// Prints out the standar error message if a key entered by the user is not one of the available options.
const void Menu::PrintInvalidOption() const
{
	std::cout << "^^^^^ Invalid Key Entered ^^^^^" << std::endl;
	PrintGap(2);
}

// Prints out a single line divider to help make text easier to read.
const void Menu::PrintSeperator()
{
	std::cout << "====================================================" << std::endl;
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
		std::cout << "Menu() DEFAULT - Invalid Key Entered." << std::endl;
		break;
	}
}

// Cycles through the option key map and prints every item to the console.
const void Menu::ShowAllOptions() const
{
	for (auto const &item : optionKeys)
	{
		std::cout << item.first << ".     " << item.second << std::endl;

		// Pause for a short time. This hopefully makes the menu easier to read instead of just puking a chunk of text onto the screen.
		game.GetTimer().Wait(.33);
	}

	PrintGap(1);
	std::cout << "-----Please enter a number from the available options.-----" << std::endl;
}

// Print the default welcome message to the console.
const void Menu::ShowWelcomeMessage() const
{
	PrintGap(1);
	std::cout << GetWelcomeMessage() << std::endl;
	PrintGap(1);
}

// See if the key pressed is one of the available options.
void Menu::ValidateKeyPressed(std::string key) const
{
	if (IsOptionKeyPresent(key))
		std::cout << "Valid Option." << std::endl;
	else
		std::cout << "-----Not a valid choice. Please try again.-----" << std::endl;
}