#include "stdafx.h"
#include "Story.h"


Story::Story()
{
	gameIntros = new std::vector < std::string > ;
	characterClassSelectionQuips = new std::vector<std::string>;
	nameSelectionQuips = new std::vector<std::string>;

	WriteGameIntros();
}


Story::~Story()
{
	delete characterClassSelectionQuips;
	delete gameIntros;
	delete nameSelectionQuips;
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