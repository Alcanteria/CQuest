#include "stdafx.h"
#include "CharacterSelectMenu.h"

CharacterSelectMenu::CharacterSelectMenu(Game* game) : Menu(game)
{
	welcomeMessage = "**********Choose a Character Class.**********";
	
	int i = 0;

	for (auto& item : characterClasses)
	{
		//char number = i + 1;
		AddOptionKey(i + 1, characterClasses.at(i));
		i++;
	}
	//char number = i + 1;
	//AddOptionKey('1', ".");
	AddOptionKey(i + 1, "Exit.");
}


CharacterSelectMenu::~CharacterSelectMenu()
{
}

void CharacterSelectMenu::CheckKeyPressed(char key) const
{

}

void CharacterSelectMenu::ProcessOptionKeyPress(char key) const
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