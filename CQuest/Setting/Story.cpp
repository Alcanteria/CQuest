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
	delete gameIntros;
	delete characterClassSelectionQuips;
	delete nameSelectionQuips;
}

const void Story::WriteGameIntros()
{
	gameIntros->push_back("Well hello there, nerd.\nFeel like playing a fake adventure \nfor some randomly awarded fake treasure?\nGood.\nMe too.");
}