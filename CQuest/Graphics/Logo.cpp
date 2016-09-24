#include "stdafx.h"
#include "Logo.h"
#include <fstream>
#include <iostream>
#include "Core\Game.h"

const std::string Logo::LOGO_FILE_NAME = "Data\\Logo.txt";

Logo::Logo(Game& gameReference) : game(gameReference)
{
}


Logo::~Logo()
{
}

const void Logo::ShowLogo() const
{
	std::ifstream in(Logo::LOGO_FILE_NAME);
	std::string text;

	std::cout << "Welcome to..." << std::endl;

	// Dramatic Pause
	GetGame().GetTimer().Wait(1.5);

	// This makes sure the file is readable. If we got this far it damn well should be.
	if (in.is_open())
	{
GetGame().GetDebugger().Print("Reading logo file...");
		while (std::getline(in, text))
		{
			if (text != "")
			{	
				std::cout << text << std::endl;
				GetGame().GetTimer().Wait(.25);
			}
		}
		in.close();
	}
	// If for some reason we still can't read the save file, just generate some new random values.
	else
	{
GetGame().GetDebugger().Print("Cannot open logo file.");
	}
}