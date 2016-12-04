#include "stdafx.h"
#include "StorySelectMenu.h"
#include "Core\Game.h"
#include <map>
#include <iostream>


StorySelectMenu::StorySelectMenu(Game& gameReference) : Menu(gameReference)
{
}


StorySelectMenu::~StorySelectMenu()
{
}

/*
****Adds every story in the story file directory to the list of options.
*/
void StorySelectMenu::AddStoryOptions()
{
Debug::Print("StorySelectMenu::AddStoryOptions()", Debug::PRIORITY::MID);

	// Create a local copy of the story names map so we don't break the rules of const-ness.
	std::map<std::string, std::string> myMap = GetGame().GetDM().GetStoryNames();

	// Loop through the map, extracting the story ID and story name from each entry.
	for (std::map<std::string, std::string>::iterator it = myMap.begin(); it != myMap.end(); ++it)
	{
Debug::Print("StorySelectMenu::AddStoryOptions() - Adding new story option to menu...", Debug::PRIORITY::MID);

		// Add the ID to the vector;
		storyIDs.push_back(it->first);

		/*	Add the option key to this menu's list of options. Use the size of the story ID vector to assign an option number.
		This SHOULD automatically correlate with the order the options are added, i.e. 1,2,3,4 etc. */
		AddOptionKey(std::to_string(storyIDs.size()), it->second);

Debug::Print("StorySelectMenu::AddStoryOptions() - " + std::to_string(storyIDs.size()) + "\t" + it->first + "\t" + it->second, Debug::PRIORITY::MID);
	}

	// Add the "Back" and "Exit" buttons to the end of the option key list.
	AddOptionKey(std::to_string(storyIDs.size() + 1), Menu::GO_BACK);
	AddOptionKey(std::to_string(storyIDs.size() + 2), Menu::EXIT);
}

/*
****Set up the menu to display the available stories and welcome message.
*/
void StorySelectMenu::Initialize()
{ 
Debug::Print("StorySelectMenu::Initialize()", Debug::PRIORITY::LOW);

	AddStoryOptions();

	welcomeMessage = "**********Please select a story to play through.**********";	
}

/*
****Performs the appropriate action based on the key entered by the player.
*/
void StorySelectMenu::ProcessOptionKeyPress(std::string key)
{
	// Convert the input to an int.
	unsigned int keyAsInt = std::stoi(key);

	// Was having issues doing this as a switch so I had to do the key checking with an ugly else if block.
	if (keyAsInt <= storyIDs.size() && keyAsInt >= 0)
	{
Debug::Print("Story Selected.", Debug::PRIORITY::LOW);

		GetGame().GetDM().SetCurrentStoryID(storyIDs.at(keyAsInt - 1));
	}
	else if (keyAsInt == storyIDs.size() + 1)
		GetGame().GoBackToPreviousMenu();
	else if (keyAsInt == storyIDs.size() + 2)
		GetGame().EndGame();
}

/*
****Makes sure that the key the player entered is one of the available options.
*/
void StorySelectMenu::ValidateKeyPressed(std::string key)
{
	if (IsOptionKeyPresent(key))
	{
		ProcessOptionKeyPress(key);
	}
	else
	{
		std::cout << "Not a valid option. Please try again." << std::endl;
	}
}