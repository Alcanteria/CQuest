#include "stdafx.h"
#include "SaveData.h"
#include <fstream>
#include <iostream>
#include <string>
#include "Core\Game.h"

#define DEBUG_MODE = 1

const std::string SaveData::INTRO_SAVE_FILE_NAME = "Data\\IntroData.txt";
const std::string SaveData::TEST_FILE_NAME = "Data\\TestFile.txt";

SaveData::SaveData(Game& gameReference) : game(gameReference)
{
	introRolls = new std::vector < int > ;
}


SaveData::~SaveData()
{
	delete introRolls;
}

// Create a file for the intro save data using new values. This will ignore any roll "history".
const void SaveData::CreateDefaultIntroSaveFile() const
{
	// File writer object.
	std::ofstream outputFile(SaveData::INTRO_SAVE_FILE_NAME);
	
	// String to store all of the text to be written.
	std::string newData;
	
	// Loop a number a times equal to the defined "History Count". This is a static int defined in the SaveData class.
	for (int i = 0; i < SaveData::INTRO_ROLL_HISTORY_COUNT; i++)
	{
		// Get a die roll from 0 to the defined (in Dice class) number of intros stored in the history.
		int roll = GetGame().GetDice().Roll(0, Dice::NUMBER_OF_INTROS);

		// Create a placeholder string.
		std::string finalString;

		// Combine the die roll with a line terminator.
		finalString = std::to_string(roll) + "\n";

		// Append the output string with the combined roll and line terminator.
		newData.append(finalString);
	}

	outputFile << newData << std::endl;

	outputFile.close();
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

// Looks for the presence of the intro data save file.
const bool SaveData::VerifyIntroSaveData() const
{
	std::ifstream file(SaveData::INTRO_SAVE_FILE_NAME.c_str());

#if defined(DEBUG_MODE)
	std::cout << "Looking for IntroData.txt in " << SaveData::INTRO_SAVE_FILE_NAME.c_str() << std::endl;
#endif

	return file.good();
}

// Verify that all of the save files are present, and take the necessary measures if they aren't found.
const void SaveData::VerifySaveData() const
{
	if (VerifyIntroSaveData())
	{
#if defined(DEBUG_MODE)
		std::cout << "Intro save data found." << std::endl;
#endif
	}
}

const void SaveData::VerifyTestData() const
{
	std::ifstream file(SaveData::TEST_FILE_NAME.c_str());

	if (file.good())
	{
		std::cout << "Test file found." << std::endl;
	}
	else
	{
		WriteTestFile();
	}
}

const void SaveData::WriteTestFile() const
{
	std::ofstream outputFile(SaveData::TEST_FILE_NAME);

	// String to store all of the text to be written.
	std::string newData;

	// Loop a number a times equal to the defined "History Count". This is a static int defined in the SaveData class.
	for (int i = 0; i < SaveData::INTRO_ROLL_HISTORY_COUNT; i++)
	{
		// Get a die roll from 0 to the defined (in Dice class) number of intros stored in the history.
		int roll = GetGame().GetDice().Roll(0, Dice::NUMBER_OF_INTROS);

		// Create a placeholder string.
		std::string finalString;

		// Combine the die roll with a line terminator.
		finalString = std::to_string(roll) + "\n";

		// Append the output string with the combined roll and line terminator.
		newData.append(finalString);
	}

	outputFile << newData << std::endl;

	outputFile.close();
}