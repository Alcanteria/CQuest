#include "stdafx.h"
#include "SaveData.h"
#include <fstream>
#include <iostream>
#include <string>
#include "Core\Game.h"

const std::string SaveData::INTRO_SAVE_FILE_NAME	= "Data\\IntroData.txt";
const std::string SaveData::TEST_FILE_NAME			= "Data\\TestFile.txt";

SaveData::SaveData(Game& gameReference) : game(gameReference)
{
	introRolls = new std::vector < int > ;
}


SaveData::~SaveData()
{
	delete	introRolls;
			introRolls = nullptr;
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

	// Write the new text into the output file.
	outputFile << newData << std::endl;

	outputFile.close();
}

// Generate a set of random numbers and add them to the introValues vector.
const void SaveData::GenerateRandomIntroValues() const
{
	// Loop a number a times equal to the defined "History Count". This is a static int defined in the SaveData class.
	for (int i = 0; i < SaveData::INTRO_ROLL_HISTORY_COUNT; i++)
	{
		// Get a die roll from 0 to the defined (in Dice class) number of intros stored in the history.
		int roll = GetGame().GetDice().Roll(0, Dice::NUMBER_OF_INTROS);

		// Add the roll to the vector.
		introRolls->push_back(roll);
	}
}

// Read in the file for the intro save data or load default values if no file can be read.
const void SaveData::ReadIntroSaveData() const
{
	std::ifstream in(SaveData::INTRO_SAVE_FILE_NAME);
	std::string text;
	
	// This makes sure the file is readable. If we got this far it damn well should be.
	if (in.is_open())
	{
		while (std::getline(in, text))
		{
			GetGame().GetDebugger().Print("File output...");
			GetGame().GetDebugger().Print(text);

			introRolls->push_back(std::stoi(text));

			GetGame().GetDebugger().Print("Variable output...");
			GetGame().GetDebugger().Print(std::to_string(introRolls->back()));
		}
		in.close();
	}
	// If for some reason we still can't read the save file, just generate some new random values.
	else
	{
		GenerateRandomIntroValues();
	}
}

// Looks for the presence of the intro data save file.
const bool SaveData::VerifyIntroSaveData() const
{
	std::ifstream file(SaveData::INTRO_SAVE_FILE_NAME.c_str());

	GetGame().GetDebugger().Print("Looking for IntroData.txt in...");
	GetGame().GetDebugger().Print(SaveData::INTRO_SAVE_FILE_NAME);

	return file.good();
}

// Verify that all of the save files are present, and take the necessary measures if they aren't found.
const void SaveData::VerifySaveData() const
{
	if (VerifyIntroSaveData())
	{
		GetGame().GetDebugger().Print("Intro save data found.");
		ReadIntroSaveData();
	}
	else
	{
		GetGame().GetDebugger().Print("Intro save data not found.");
		WriteDefaultIntroSaveData();
	}
}

const void SaveData::VerifyTestData() const
{
	std::ifstream file(SaveData::TEST_FILE_NAME.c_str());

	if (file.good())
	{
		GetGame().GetDebugger().Print("Test file found.");
	}
	else
	{
		WriteTestFile();
	}
}

const void SaveData::WriteDefaultIntroSaveData() const
{
	GetGame().GetDebugger().Print("SaveData::WriteDefaultIntroSaveData() - Writing Intro Save Data file.");

	std::ofstream outputFile(SaveData::INTRO_SAVE_FILE_NAME);

	// String to store all of the text to be written.
	std::string newData;

	for (int i : introRolls)
	{

	}

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