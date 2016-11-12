#include "stdafx.h"
#include "DM.h"
#include "Core\Game.h"
#include <Windows.h>
#include "Core\Debugger.h"
#include <fstream>

// Placeholder to indicate no story has been selected yet.
const std::string DM::NO_STORY = "NONE";

// Location of the story files.
const std::string DM::STORY_FILE_PATH = "Data\\Stories";

DM::DM(Game& gameReference) : game(gameReference)
{
	currentStoryID = new std::string();
	storyDescriptions = new std::map<std::string, std::string>();
	storyFileNames = new std::map<std::string, std::string>();
	storyNames = new std::map<std::string, std::string>();
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

GetGame().GetDebugger().Print("DM() Destructor.");
}

// Take a file name as an argument and returns the unique ID contained within the file.
const std::string DM::ExtractStoryIDFromFile(std::string fileName) const
{
	std::ifstream in(DM::STORY_FILE_PATH + fileName);
	std::string line;
	bool IDFound;

	// This makes sure the file is readable.
	if (in.is_open())
	{
		while (std::getline(in, line))
		{
			if (line != "")
			{
				if (line == "@")
				{
					std::getline(in, line);
					IDFound = true;
GetGame().GetDebugger().Print("DM::ExtractStoryIDFromFile() - ID Found: " + line);
					break;
				}
				
			}
		}
		in.close();
	}

	if (!IDFound)
	{
		line = DM::NO_STORY;
GetGame().GetDebugger().Print("DM::ExtractStoryIDFromFile() - No ID Found: " + line);
	}

	return line;
}

// Grabs all of the files in the Story directory, weeding out other files that may be in there.
const std::vector<std::string> DM::GetAllStoryFilesInDirectory() const
{
GetGame().GetDebugger().Print("DM::GetAllStoryFilesInDirectory()...");
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

// Print out all the file names found. Dubugging use only to make sure this works.
if (Debugger::DEBUG_MODE)
{
	std::string	output = "There are ";
				output.append(std::to_string(fileNames.size()));
				output.append(" files in the folder, and they are..");

	GetGame().GetDebugger().Print(output);

	for (auto i : fileNames)
	{
		GetGame().GetDebugger().Print(i);
	}
}

	return fileNames;
}

// Performs the functions that need to be done at the launch of the program.
void DM::Initialize() const
{
GetGame().GetDebugger().Print("DM::Initialize() - Initializing DM Class.");

	StoreStoryFileNames();
}

void DM::ReadStoryFiles() const
{

}

// Looks through the default directory that stores story files and collects all of the file names.
void DM::StoreStoryFileNames() const
{
GetGame().GetDebugger().Print("DM::StoreStoryFileNames()...");

	std::vector<std::string> fileNames = GetAllStoryFilesInDirectory();

if (GetGame().GetDebugger().DEBUG_MODE)
{
GetGame().GetDebugger().Print("DM::StoreStoryFiles - Files stored:");
	for (auto i : fileNames) // If vector is a pointer, make sure you put the star in front of the name, i.e. *vector
	{
GetGame().GetDebugger().Print(i);
	}
}
}