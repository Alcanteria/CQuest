#include "stdafx.h"
#include "CharacterSelectMenu.h"
#include <iostream>
#include "..\Characters\CharacterClass.h"
#include "..\Core\Game.h"

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

void CharacterSelectMenu::CheckKeyPressed(std::string key) const
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

void CharacterSelectMenu::ProcessOptionKeyPress(std::string key) const
{
	int input = std::stoi(key);

	switch (input)
	{
	case CharacterClass::CLASSES::BARBARIAN:
		std::cout << "You picked Barbarian." << std::endl;
		break;
	case CharacterClass::CLASSES::CLERIC:
		std::cout << "You picked Cleric." << std::endl;
		break;
	case CharacterClass::CLASSES::FIGHTER:
		std::cout << "You picked Fighter." << std::endl;
		break;
	case CharacterClass::CLASSES::RANGER:
		std::cout << "You picked Ranger." << std::endl;
		break;
	case CharacterClass::CLASSES::ROGUE:
		std::cout << "You picked Rogue." << std::endl;
		break;
	case CharacterClass::CLASSES::WIZARD:
		std::cout << "You picked Wizard." << std::endl;
		break;
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