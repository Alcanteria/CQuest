#include "stdafx.h"
#include "SaveData.h"
#include <fstream>
#include <iostream>
#include <string>

#define DEBUG_MODE = 1

const std::string SaveData::INTRO_SAVE_FILE_NAME = "Data\\Text.txt";

SaveData::SaveData()
{
	introRolls = new std::vector < int > ;
}


SaveData::~SaveData()
{
	delete introRolls;
}

const void SaveData::ReadIntroSaveData()
{
	std::ifstream in(SaveData::INTRO_SAVE_FILE_NAME);
	std::string text;
	
	if (in.is_open())
	{
		while (std::getline(in, text))
		{
			std::cout << text << std::endl;
		}
		in.close();
	}
}

// Looks for the presence of the save file.
const bool SaveData::CheckForIntroSaveData()
{
	std::ifstream file(SaveData::INTRO_SAVE_FILE_NAME.c_str());

#if defined(DEBUG_MODE)
	std::cout << "Looking in " << SaveData::INTRO_SAVE_FILE_NAME.c_str() << std::endl;
#endif

	return file.good();
}