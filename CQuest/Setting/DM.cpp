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
	storyDescriptions = new std::map<std::string, std::string>();
	storyFileNames = new std::map<std::string, std::string>();
	storyNames = new std::map<std::string, std::string>();
	storyFileReader = new StoryFileReader(gameReference);
}


DM::~DM()
{
	delete	currentStoryID;
			currentStoryID = nullptr;
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

// Performs the functions that need to be done at the launch of the program.
void DM::Initialize() const
{
GetGame().GetDebugger().Print("DM::Initialize() - Initializing DM Class.", Debugger::PRIORITY::LOW);

	*storyFileNames = storyFileReader->GetStoryFileNames();

if (Debugger::DEBUG_MODE == Debugger::PRIORITY::MID)
{
GetGame().GetDebugger().Print("DM::Initialize() - File names with story IDs...", Debugger::PRIORITY::MID);
for (std::map<std::string, std::string>::iterator it = storyFileNames->begin(); it != storyFileNames->end(); ++it)
{
GetGame().GetDebugger().Print(it->first + "\t" + it->second, Debugger::PRIORITY::MID);
}
}
}