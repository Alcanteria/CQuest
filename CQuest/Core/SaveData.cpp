#include "stdafx.h"
#include "SaveData.h"
#include <fstream>
#include <iostream>
#include <string>
#include "Core\Game.h"

const std::string SaveData::INTRO_ROLL_HISTORY_FILENAME		= "Data\\IntroRollHistory.txt";
const std::string SaveData::INTRO_STORY_TEXT_FILENAME		= "Data\\Introductions.txt";
const std::string SaveData::TEST_FILE_NAME					= "Data\\TestFile.txt";

SaveData::SaveData(Game& gameReference) : game(gameReference)
{
	introRolls = new std::vector < int > ;

	ReadIntroStoryText();
}


SaveData::~SaveData()
{
	delete	introRolls;
			introRolls = nullptr;
}

/* 
****Adds a new roll to the FRONT of the roll history.
*/
void SaveData::AddNewIntroRollToHistory(int roll) const
{
if (Tools::Debug::DEBUG_MODE == Tools::Debug::PRIORITY::LOW)
{
Tools::Debug::Print("SaveData::AddNewIntroRollToHistory() - Intro history before adding new number...", Tools::Debug::PRIORITY::LOW);
PrintIntroRollHistory();
}
	
	// Add the new roll to the front of the vector;
	introRolls->insert(introRolls->begin(), roll);

	// Trim off the excess values at the end of the vector.
	introRolls->resize(SaveData::INTRO_ROLL_HISTORY_COUNT);

	// Save the file.
	SaveIntroData();

if (Tools::Debug::DEBUG_MODE == Tools::Debug::PRIORITY::LOW)
{
Tools::Debug::Print("SaveData::AddNewIntroRollToHistory() - Intro history after adding new number...", Tools::Debug::PRIORITY::LOW);
PrintIntroRollHistory();
}
}

/* 
****Create a file for the intro save data using new values. This will ignore any roll "history".
*/
void SaveData::CreateDefaultIntroSaveFile()
{
Tools::Debug::Print("SaveData::CreateDefaultIntroSaveFile() - Creating default save file.", Tools::Debug::PRIORITY::LOW);
	
	GenerateRandomIntroValues();

	SaveIntroData();
}

/* 
****Generate a set of random numbers and add them to the introValues vector.
*/
void SaveData::GenerateRandomIntroValues()
{
	// Clean out whatever was already in the vector. Most likely nothing at all.
	introRolls->clear();

	// Loop a number a times equal to the defined "History Count". This is a static int defined in the SaveData class.
	for (int i = 0; i < SaveData::INTRO_ROLL_HISTORY_COUNT; i++)
	{
		bool unique = false;

		int uniqueRoll;

		while (!unique)
		{
			// Get a random number between zero and the size of the gameIntros vector.
			uniqueRoll = Tools::Dice::Roll(0, GetGame().GetDM().GetIntros().size() - 1);

			// Use the std library's vector find function to see if our new roll is a duplicate. Returns TRUE if it is NOT found.
			if (std::find(introRolls->begin(), introRolls->end(), uniqueRoll) == introRolls->end())
			{
				unique = true;

				introRolls->push_back(uniqueRoll);
Tools::Debug::Print("Story::GetNewIntroDiceRoll() - Unique roll found. Roll is...", Tools::Debug::PRIORITY::LOW);
Tools::Debug::Print(std::to_string(uniqueRoll), Tools::Debug::PRIORITY::LOW);

if (Tools::Debug::DEBUG_MODE == Tools::Debug::PRIORITY::LOW)
{
GetGame().GetSaveData().PrintIntroRollHistory();
}
			}
		}
	}
}

/* 
****Prints all of the intro roll history to the console. This is for debugging purposes.
*/
void SaveData::PrintIntroRollHistory() const
{
Tools::Debug::Print("Current intro roll history...", Tools::Debug::PRIORITY::LOW);

for (auto i : *introRolls)
{
Tools::Debug::Print(std::to_string(i), Tools::Debug::PRIORITY::LOW);
}
}

/* 
****Read in the file for the intro save data or load default values if no file can be read.
*/
void SaveData::ReadIntroRollHistory()
{
	std::ifstream in(SaveData::INTRO_ROLL_HISTORY_FILENAME);
	std::string text;
	
	// This makes sure the file is readable. If we got this far it damn well should be.
	if (in.is_open())
	{
		while (std::getline(in, text))
		{
			if (text != "")
			{
Tools::Debug::Print("File output...", Tools::Debug::PRIORITY::LOW);
Tools::Debug::Print(text, Tools::Debug::PRIORITY::LOW);

				introRolls->push_back(std::stoi(text));

Tools::Debug::Print("Variable output...", Tools::Debug::PRIORITY::LOW);
Tools::Debug::Print(std::to_string(introRolls->back()), Tools::Debug::PRIORITY::LOW);
			}
		}
		in.close();
	}
	// If for some reason we still can't read the save file, just generate some new random values.
	else
	{
		GenerateRandomIntroValues();
	}
}

/* 
****Reads the story text from the external file and loads it into a vector.
*/
void SaveData::ReadIntroStoryText()
{
	std::ifstream in(SaveData::INTRO_STORY_TEXT_FILENAME);
	std::string text;

	// This makes sure the file is readable. If we got this far it damn well should be.
	if (in.is_open())
	{
		// Start reading from the first line in the file.
		while (std::getline(in, text))
		{
			// If the line isn't blank...
			if (text != "")
			{
				// If the line has the tilde character, which signals the start/stop of an entry...
				if (text == "~")
				{
					// Grab the next line...
					std::getline(in, text);

					// Push it into the vector...
					GetGame().GetDM().GetIntros().push_back(text);

					// Go to the next line...
					std::getline(in, text);

					// While we don't see the end of entry character...
					while (text != "~")
					{
						// Add the new chunk of text and with a line terminator in front...
						GetGame().GetDM().GetIntros().back().append("\n");
						GetGame().GetDM().GetIntros().back().append(text);

						// Go to the next line.
						std::getline(in, text);
					}
				}				
Tools::Debug::Print("Read from file...", Tools::Debug::PRIORITY::LOW);
Tools::Debug::Print(GetGame().GetDM().GetIntros().back(), Tools::Debug::PRIORITY::LOW);
			}
		}
		in.close();
	}
}

/*
****
*/
void SaveData::SaveIntroData() const
{
Tools::Debug::Print("SaveData::SaveIntroData() - Writing Intro Save Data file.", Tools::Debug::PRIORITY::LOW);

std::ofstream outputFile(SaveData::INTRO_ROLL_HISTORY_FILENAME);

	// String to store all of the text to be written.
	std::string newData;

	// Loop through vector of roll values and add them as text to the save file.
	for (auto i : *introRolls)
	{
		std::string finalString;

		finalString = std::to_string(i) + "\n";

		newData.append(finalString);
	}

	outputFile << newData;

	outputFile.close();
}

/* 
****Looks for the presence of the intro data save file.
*/
const bool SaveData::VerifyIntroSaveData() const
{
	std::ifstream file(SaveData::INTRO_ROLL_HISTORY_FILENAME.c_str());

Tools::Debug::Print("Looking for IntroData.txt in...", Tools::Debug::PRIORITY::LOW);
Tools::Debug::Print(SaveData::INTRO_ROLL_HISTORY_FILENAME, Tools::Debug::PRIORITY::LOW);

	return file.good();
}

/* 
****Verify that all of the save files are present, and take the necessary measures if they aren't found.
*/
void SaveData::VerifySaveData()
{
	if (VerifyIntroSaveData())
	{
Tools::Debug::Print("Intro save data found.", Tools::Debug::PRIORITY::LOW);

		ReadIntroRollHistory();
	}
	else
	{
Tools::Debug::Print("Intro save data not found.", Tools::Debug::PRIORITY::TOP);

		CreateDefaultIntroSaveFile();
	}
}

/*
****
*/
void SaveData::VerifyTestData()
{
	std::ifstream file(SaveData::TEST_FILE_NAME.c_str());

	if (file.good())
	{
Tools::Debug::Print("Test file found.", Tools::Debug::PRIORITY::LOW);
	}
	else
	{
		WriteTestFile();
	}
}

/*
****
*/
void SaveData::WriteTestFile()
{
	std::ofstream outputFile(SaveData::TEST_FILE_NAME);

	// String to store all of the text to be written.
	std::string newData;

	// Loop a number a times equal to the defined "History Count". This is a static int defined in the SaveData class.
	for (int i = 0; i < SaveData::INTRO_ROLL_HISTORY_COUNT; i++)
	{
		// Get a die roll from 0 to the defined (in Dice class) number of intros stored in the history.
		int roll = Tools::Dice::Roll(0, GetGame().GetDM().GetIntros().size() - 1);

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