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

void Logo::ShowLogo() const
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
	else
	{
		std::cout << "Aww, shit. Can't read the logo file. Here, how's this for a logo:" << std::endl;
		GetGame().GetTimer().Wait(3);
		std::cout << "8======D" << std::endl;

GetGame().GetDebugger().Print("Cannot open logo file.");
	}
}