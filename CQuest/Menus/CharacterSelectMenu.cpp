#include "stdafx.h"
#include "CharacterSelectMenu.h"
#include <iostream>
#include "..\Characters\CharacterClass.h"
#include "..\Core\Game.h"

CharacterSelectMenu::CharacterSelectMenu(Game* game) : Menu(game)
{
	welcomeMessage = "**********Choose a Character Class.**********";
	
	// Create an iterator to help automatically grab class name indices in the loop.
	int i = 0;

	for (auto& item : CharacterClass::CLASS_NAMES)
	{
		// Skip the first item in the vector, since it is zero and we aren't using zero in our option lists.
		if (i != 0)
		{
			// Get the string of the number of the iterator, and add the option key for that number and the character class name in the character class vector.
			std::string number = std::to_string(i);
			AddOptionKey(number, CharacterClass::CLASS_NAMES.at(i));
			//AddOptionKey(number, characterClasses.at(i));
		}
		
		i++;
	}

	// Add the option to go back to the previous menu.
	std::string backNumber = std::to_string(i);
	AddOptionKey(backNumber, Menu::GO_BACK);
	
	// Add the exit option as the last option.
	std::string exitNumber = std::to_string(i + 1);
	AddOptionKey(exitNumber, Menu::EXIT);
}


CharacterSelectMenu::~CharacterSelectMenu()
{
}

void CharacterSelectMenu::ValidateKeyPressed(std::string key) const
{
	if (IsOptionKeyPresent(key))
	{
		ProcessOptionKeyPress(key);
	}
	else
	{
		PrintInvalidOption();
	}
}

// Determine what is to be done with the key entered by the user.
void CharacterSelectMenu::ProcessOptionKeyPress(std::string key) const
{
	// Convert the key press from a string to an int so we can do numberic value checks.
	int input = std::stoi(key);

	// If the value is less than the NUMBER_OF_CLASSES + 1 enum, it means a class was selected from the list.
	if (input < CharacterClass::CLASSES::NUMBER_OF_CLASSES + 1)
	{
		std::cout << "You picked a " << CharacterClass::CLASS_NAMES.at(input) << std::endl;
		PrintGap();
	}
	// If a value greater than or equal to the NUMBER_OF_CLASSES + 1 enum was selected, than one of the menu navigation options was selected.
	else
	{
		switch (input)
		{
		case CharacterClass::CLASSES::NUMBER_OF_CLASSES + 1:
			game->ChangeMenu(game->previousMenu);
			break;
		case CharacterClass::CLASSES::NUMBER_OF_CLASSES + 2:
			game->EndGame();
			break;
		default:
			PrintInvalidOption();
			break;
		}
	}
}

// Prompts the user to name their character.
const void CharacterSelectMenu::NameCharacter()
{
	// TODO: Create input prompt to allow user to enter in a character name. Need to figure out how to read more than just the first character of the input.
	//game->NameCharacter(name);
}