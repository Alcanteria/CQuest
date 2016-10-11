#include "stdafx.h"
#include "DM.h"
#include "Core\Game.h"
#include <Windows.h>
#include "Core\Debugger.h"

// Placeholder to indicate no story has been selected yet.
const std::string DM::NO_STORY = "NONE";

// Location of the story files.
const std::string DM::STORY_FILE_PATH = "Data\\Stories";

DM::DM(Game& gameReference) : game(gameReference)
{
	currentStoryID = new std::string();
	storyDescriptions = new std::map<std::string, std::string>();
	storyFiles = new std::map<std::string, std::string>();
	storyNames = new std::map<std::string, std::string>();
}


DM::~DM()
{
	delete	currentStoryID;
			currentStoryID = nullptr;
	delete	storyDescriptions;
			storyDescriptions = nullptr;
	delete	storyFiles;
			storyFiles = nullptr;
	delete	storyNames;
			storyNames = nullptr;

GetGame().GetDebugger().Print("DM() Destructor.");
}

// Grabs all of the files in the Story directory, weeding out other files that may be in there.
void DM::GetAllStoryFilesInDirectory() const
{
	// Store for all found file names.
	std::vector<std::string> fileNames;

	// UGLY WINDOWS SHIT.
	WIN32_FIND_DATAA fileData;
	HANDLE hFind;

	// Note: this wasn't working until I added the "/*" to the directory.
	hFind = FindFirstFileA((DM::STORY_FILE_PATH + "/*").c_str(), &fileData);

	// More UGLY windows shit.
	if (hFind != INVALID_HANDLE_VALUE)
	{
		do
		{
			// Check if the file found is a folder.
			const bool is_directory = (fileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) != 0;

		/*	Check if the file found is the default "back" dots thingy. I don't know what you call that.
			Skip it if it is. */
			if (fileData.cFileName[0] == '.')
				continue;

			// Skip the file if it is a directory.
			if (is_directory)
				continue;

			// Add the file name to the vector of names.
			fileNames.push_back(fileData.cFileName);
		} 
		while (FindNextFileA(hFind, &fileData));
	}

	// Don't let the door hit you in the ass on your way out.
	FindClose(hFind);

// Print out all the file names found. Dubugging only to make sure this works.
if (Debugger::DEBUG_MODE)
{
	std::cout << "There are " << fileNames.size() << " files in the folder, and they are.." << std::endl;

	for (auto i : fileNames)
	{
		std::cout << i << std::endl;
	}
}
}

void DM::ReadStoryFiles() const
{

}