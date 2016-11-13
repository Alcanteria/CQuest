#include "stdafx.h"
#include "DM.h"
#include "Core\Game.h"
#include <Windows.h>
#include "Core\Debugger.h"

// Placeholder to indicate no story has been selected yet.
const std::string DM::NO_STORY = "NONE";

DM::DM(Game& gameReference) : game(gameReference)
{
	currentStoryID = new std::string();
	gameIntros = new std::vector<std::string>;
	storyDescriptions = new std::map<std::string, std::string>();
	storyFileNames = new std::map<std::string, std::string>();
	storyNames = new std::map<std::string, std::string>();
	storyFileReader = new StoryFileReader(gameReference);
}


DM::~DM()
{
	delete	currentStoryID;
			currentStoryID = nullptr;
	delete	gameIntros;
			gameIntros = nullptr;
	delete	storyDescriptions;
			storyDescriptions = nullptr;
	delete	storyFileNames;
			storyFileNames = nullptr;
	delete	storyNames;
			storyNames = nullptr;
	delete	storyFileReader;
			storyFileReader = nullptr;

GetGame().GetDebugger().Print("DM() Destructor.", Debugger::PRIORITY::LOW);
}

/*
****Roll a die and compare the result to the saved history of rolls.
****Keep rolling until you get a roll  that isn't in the history.
*/
const int DM::GetNewIntroDiceRoll() const
{
	bool unique = false;

	int uniqueRoll;

	while (!unique)
	{
		// Get a random number between zero and the size of the gameIntros vector.
		uniqueRoll = GetGame().GetDice().Roll(0, gameIntros->size() - 1);

		// Use the std library's vector find function to see if our new roll is in the roll history.
		if (std::find(GetGame().GetSaveData().GetIntroRolls().begin(),
			GetGame().GetSaveData().GetIntroRolls().end(), uniqueRoll) == GetGame().GetSaveData().GetIntroRolls().end())
		{
			unique = true;

GetGame().GetDebugger().Print("DM::GetNewIntroDiceRoll() - Unique roll found. Roll is...", Debugger::PRIORITY::LOW);
GetGame().GetDebugger().Print(std::to_string(uniqueRoll), Debugger::PRIORITY::LOW);

if (Debugger::DEBUG_MODE == Debugger::PRIORITY::LOW)
{
GetGame().GetSaveData().PrintIntroRollHistory();
}
		}
	}

	return uniqueRoll;
}

/*
****Returns intro dialogue that has not been seen within the recorded game history.
*/
const std::string DM::GetRandomIntro() const
{
	int poop = GetNewIntroDiceRoll();

	GetGame().GetSaveData().AddNewIntroRollToHistory(poop);

	return gameIntros->at(poop);
}

/* 
****Performs the functions that need to be done at the launch of the program.
*/
void DM::Initialize() const
{
GetGame().GetDebugger().Print("DM::Initialize() - Initializing DM Class.", Debugger::PRIORITY::MID);

	// Populate the map with the story IDs and file names.
	*storyFileNames = storyFileReader->GetStoryFileNames();

if (Debugger::DEBUG_MODE == Debugger::PRIORITY::MID)
{
for (std::map<std::string, std::string>::iterator it = storyFileNames->begin(); it != storyFileNames->end(); ++it)
{
GetGame().GetDebugger().Print(it->first + "\t" + it->second, Debugger::PRIORITY::MID);
}
}

	// Populate the map with the story IDs and names.
	*storyNames = storyFileReader->GetStoryNames();

if (Debugger::DEBUG_MODE == Debugger::PRIORITY::MID)
{
for (std::map<std::string, std::string>::iterator it = storyNames->begin(); it != storyNames->end(); ++it)
{
GetGame().GetDebugger().Print(it->first + "\t" + it->second, Debugger::PRIORITY::MID);
}
}

	// Populate the map with the story IDs and descriptions.
	*storyDescriptions = storyFileReader->GetStoryDescriptions();

if (Debugger::DEBUG_MODE == Debugger::PRIORITY::MID)
{
for (std::map<std::string, std::string>::iterator it = storyDescriptions->begin(); it != storyDescriptions->end(); ++it)
{
GetGame().GetDebugger().Print(it->first + "\t" + it->second, Debugger::PRIORITY::MID);
}
}
}