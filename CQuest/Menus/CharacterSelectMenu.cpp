#include "stdafx.h"
#include "CharacterSelectMenu.h"

CharacterSelectMenu::CharacterSelectMenu(Game* game) : Menu(game)
{
	welcomeMessage = "**********Choose a Character Class.**********";

	SetUpCharacterClasses();
	
	int i = 0;

	for (auto& item : characterClasses)
	{
		std::string number = std::to_string(i + 1);
		AddOptionKey(number, characterClasses.at(i));
		i++;
	}
	//char number = char(i + 1);
	//AddOptionKey('1', ".");
	std::string number = std::to_string(i + 1);
	AddOptionKey(number, "Exit.");
}


CharacterSelectMenu::~CharacterSelectMenu()
{
}

void CharacterSelectMenu::CheckKeyPressed(std::string key) const
{

}

void CharacterSelectMenu::ProcessOptionKeyPress(std::string key) const
{

}

// Populate the store of character classes.
const void CharacterSelectMenu::SetUpCharacterClasses()
{
	characterClasses.push_back("Barbarian");
	characterClasses.push_back("Cleric");
	characterClasses.push_back("Fighter");
	characterClasses.push_back("Ranger");
	characterClasses.push_back("Rogue");
	characterClasses.push_back("Wizard");
}