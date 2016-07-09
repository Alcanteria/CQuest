#include "stdafx.h"
#include "CharacterSelectMenu.h"
#include <iostream>
#include "..\Characters\CharacterClass.h"

CharacterSelectMenu::CharacterSelectMenu(Game* game) : Menu(game)
{
	welcomeMessage = "**********Choose a Character Class.**********";

	SetUpCharacterClasses();
	
	// Create an iterator to help automatically grab class name indices in the loop.
	int i = 0;

	for (auto& item : characterClasses)
	{
		// Skip the first item in the vector, since it is zero and we aren't using zero in our option lists.
		if (i != 0)
		{
			// Get the string of the number of the iterator, and add the option key for that number and the character class name in the character class vector.
			std::string number = std::to_string(i);
			AddOptionKey(number, characterClasses.at(i));
		}
		
		i++;
	}
	
	// Add the exit option as the last option.
	std::string number = std::to_string(i + 1);
	AddOptionKey(number, "*****EXIT*****");
}


CharacterSelectMenu::~CharacterSelectMenu()
{
}

void CharacterSelectMenu::CheckKeyPressed(std::string key) const
{
	if (IsOptionKeyPresent(key))
	{
		ProcessOptionKeyPress(key);
	}
	else
	{
		std::cout << "*****Not a valid option. Please try again.*****" << std::endl;
		PrintGap();
	}
}

void CharacterSelectMenu::ProcessOptionKeyPress(std::string key) const
{
	int input = std::stoi(key);
	if (input == CharacterClass::CLASSES::BARBARIAN)
		std::cout << "You picked Barbarian." << std::endl;

	PrintGap();
}

// Populate the store of character classes.
const void CharacterSelectMenu::SetUpCharacterClasses()
{
	characterClasses.push_back("None.");
	characterClasses.push_back("Barbarian");
	characterClasses.push_back("Cleric");
	characterClasses.push_back("Fighter");
	characterClasses.push_back("Ranger");
	characterClasses.push_back("Rogue");
	characterClasses.push_back("Wizard");
}