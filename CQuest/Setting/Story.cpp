#include "stdafx.h"
#include "Story.h"
#include "Core\Game.h"


Story::Story(Game& gameReference) : game(gameReference)
{
	gameIntros = new std::vector < std::string > ;
	characterClassSelectionQuips = new std::vector<std::string>;
	nameSelectionQuips = new std::vector<std::string>;

	WriteGameIntros();
}


Story::~Story()
{
	delete	characterClassSelectionQuips;
			characterClassSelectionQuips = nullptr;
	delete	gameIntros;
			gameIntros = nullptr;
	delete	nameSelectionQuips;
			nameSelectionQuips = nullptr;
}

/*	Roll a die and compare the result to the saved history of rolls. 
	Keep rolling until you get a roll  that isn't in the history. */
const int Story::GetNewIntroDiceRoll() const
{
	bool unique = false;

	int uniqueRoll;

	while (!unique)
	{
		// Get a random number between zero and the size of the gameIntros vector.
		uniqueRoll = GetGame().GetDice().Roll(0, gameIntros->size() - 1);

		// Use the std library's vector find function to see if our new roll is in the roll history.
		if (std::find(	GetGame().GetSaveData().GetIntroRolls().begin(), 
						GetGame().GetSaveData().GetIntroRolls().end(), uniqueRoll) == GetGame().GetSaveData().GetIntroRolls().end())
		{
			unique = true;

GetGame().GetDebugger().Print("Story::GetNewIntroDiceRoll() - Unique roll found. Roll is...");
GetGame().GetDebugger().Print(std::to_string(uniqueRoll));

			if (Debugger::DEBUG_MODE)
			{
				GetGame().GetSaveData().PrintIntroRollHistory();
			}
		}
	}

	return uniqueRoll;
}

// Returns intro dialogue that has not been seen within the recorded game history.
const std::string Story::GetRandomIntro() const
{
	int poop = GetNewIntroDiceRoll();

	GetGame().GetSaveData().AddNewIntroRollToHistory(poop);

	return gameIntros->at(poop);
}

const void Story::WriteCharacterSelectQuips() const
{

}

const void Story::WriteGameIntros() const
{
	gameIntros->push_back("Well hello there, nerd.\nFeel like playing a fake adventure \nfor some randomly awarded fake treasure?\nGood.\nMe too.");
	gameIntros->push_back("Nothing better to do, huh?\nLet's just get this over with.\nNo eye contact, please.");
	gameIntros->push_back("I honestly don't remember if I've seen you before.\nAll of you nerds look alike.\nLet's get started");
	gameIntros->push_back("Hello. Here to play a game? This should be fun.\nYou have a LOT of porn on your hard drive.\nNothing wrong with that. Just saying.");
	gameIntros->push_back("Hi! You are in luck. I'm in a good mood right now.\nMaybe I can nudge the random number generator a little in your favor today.");
}

const void Story::WriteNameSelectQuips() const
{
	nameSelectionQuips->push_back("That's not your real name, is it?");
	nameSelectionQuips->push_back("Wow. Very original.\nSeriously. That's not sarcasm.");
	nameSelectionQuips->push_back("Did you get that from a book? It sounds so familiar. Probably from some anime.\nNerd.");
	nameSelectionQuips->push_back("If I ever met someone with that name I'd call Child Protective Services on their parents.");
	nameSelectionQuips->push_back("This always ends up being a sort of Rorschach test, doesn't it.");
	nameSelectionQuips->push_back("This may be the hardest part of any game. At least you didn't have to pick a unique name.");
}