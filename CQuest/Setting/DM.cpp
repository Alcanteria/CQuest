#include "stdafx.h"
#include "DM.h"
#include "Core\Game.h"
#include <Windows.h>

// Placeholder to indicate no story has been selected yet.
const std::string DM::NO_STORY = "NONE";

DM::DM(Game& gameReference) : game(gameReference)
{
	currentStoryID = new std::string();
	gameIntros = new std::vector<std::string>;
	story = new Story(gameReference);
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
	delete	story;
			story = nullptr;
	delete	storyDescriptions;
			storyDescriptions = nullptr;
	delete	storyFileNames;
			storyFileNames = nullptr;
	delete	storyNames;
			storyNames = nullptr;
	delete	storyFileReader;
			storyFileReader = nullptr;

Tools::Debug::Print("DM() Destructor.", Tools::Debug::PRIORITY::LOW);
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
		uniqueRoll = Tools::Dice::Roll(0, gameIntros->size() - 1);

		// Use the std library's vector find function to see if our new roll is in the roll history.
		if (std::find(GetGame().GetSaveData().GetIntroRolls().begin(),
			GetGame().GetSaveData().GetIntroRolls().end(), uniqueRoll) == GetGame().GetSaveData().GetIntroRolls().end())
		{
			unique = true;

Tools::Debug::Print("DM::GetNewIntroDiceRoll() - Unique roll found. Roll is...", Tools::Debug::PRIORITY::LOW);
Tools::Debug::Print(std::to_string(uniqueRoll), Tools::Debug::PRIORITY::LOW);

if (Tools::Debug::DEBUG_MODE == Tools::Debug::PRIORITY::LOW)
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
Tools::Debug::Print("DM::Initialize() - Initializing DM Class.", Tools::Debug::PRIORITY::LOW);

	// Populate the map with the IDs and file names of all available story modules.
	*storyFileNames = storyFileReader->GetStoryFileNames();

if (Tools::Debug::DEBUG_MODE == Tools::Debug::PRIORITY::LOW)
{
for (std::map<std::string, std::string>::iterator it = storyFileNames->begin(); it != storyFileNames->end(); ++it)
{
Tools::Debug::Print(it->first + "\t" + it->second, Tools::Debug::PRIORITY::LOW);
}
}

	// Populate the map with the IDs and names of all available stories.
	*storyNames = storyFileReader->GetStoryNames();

if (Tools::Debug::DEBUG_MODE == Tools::Debug::PRIORITY::LOW)
{
for (std::map<std::string, std::string>::iterator it = storyNames->begin(); it != storyNames->end(); ++it)
{
Tools::Debug::Print(it->first + "\t" + it->second, Tools::Debug::PRIORITY::LOW);
}
}

	// Populate the map with the IDs and descriptions of all available stories.
	*storyDescriptions = storyFileReader->GetStoryDescriptions();

if (Tools::Debug::DEBUG_MODE == Tools::Debug::PRIORITY::LOW)
{
for (std::map<std::string, std::string>::iterator it = storyDescriptions->begin(); it != storyDescriptions->end(); ++it)
{
Tools::Debug::Print(it->first + "\t" + it->second, Tools::Debug::PRIORITY::LOW);
}
}

	// Test loading a story from file.
	storyFileReader->LoadStoryFromFile(*story, "ChickenSaga.txt");
}

/*
****Performs the required actions to:
****	*	Set the current story
****	*	Load the selected story
****	*	Create a chapter menu for the game to work with
****	*	Set the current game menu to the newly created chapter menu
*/
void DM::LoadNewStory(std::string storyID)
{
Tools::Debug::Print("DM::LoadNewStory()", Tools::Debug::PRIORITY::LOW);

	SetCurrentStoryID(storyID);
	storyFileReader->LoadStoryFromFile(*story, storyFileNames->at(storyID));
	GetGame().AddMenu(Menu::MENUS::CHAPTER, new ChapterMenu(GetGame(), story->GetCurrentChapter()));
	GetGame().GetMenu(Menu::MENUS::CHAPTER)->Initialize();
	GetGame().ChangeGameMenu(Menu::MENUS::CHAPTER);

Tools::Debug::Print("DM::LoadNewStory() - Loaded: " + storyNames->at(storyID), Tools::Debug::PRIORITY::LOW);
}