#include "stdafx.h"
#include "StorySelectMenu.h"
#include "Core\Game.h"
#include <map>


StorySelectMenu::StorySelectMenu(Game& gameReference) : Menu(gameReference)
{
}


StorySelectMenu::~StorySelectMenu()
{
}

/*
****Set up the menu to display the available stories and welcome message.
*/
void StorySelectMenu::Initialize()
{ 
GetGame().GetDebugger().Print("StorySelectMenu::Initialize()", Debugger::PRIORITY::MID);

	// Create a local copy of the story names map so we don't break the rules of const-ness.
	std::map<std::string, std::string> myMap = GetGame().GetDM().GetStoryNames();

	// Loop through the map, extracting the story ID and story name from each entry.
	for (std::map<std::string, std::string>::iterator it = myMap.begin(); it != myMap.end(); ++it)
	{
GetGame().GetDebugger().Print("StorySelectMenu::Initialize() - Adding new story option to menu...", Debugger::PRIORITY::MID);
		// Add the ID to the vector;
		storyIDs.push_back(it->first);

		/*	Add the option key to this menu's list of options. Use the size of the story ID vector to assign an option number.
			This SHOULD automatically correlate with the order the options are added, i.e. 1,2,3,4 etc. */
		AddOptionKey(std::to_string(storyIDs.size()), it->second);

GetGame().GetDebugger().Print("StorySelectMenu::Initialize() - " + std::to_string(storyIDs.size()) + "\t" + it->first + "\t" + it->second, Debugger::PRIORITY::MID);
	}
}

void StorySelectMenu::ProcessOptionKeyPress(std::string key) const
{

}

void StorySelectMenu::ValidateKeyPressed(std::string key) const
{

}