#include "stdafx.h"
#include "StoryFileReader.h"
#include "Core\Game.h"
#include <fstream>

// Location of the story files.
const std::string StoryFileReader::STORY_FILE_PATH = "Data\\Stories\\";

StoryFileReader::StoryFileReader(Game& gameReference) : game(gameReference)
{
}


StoryFileReader::~StoryFileReader()
{
}

// Take a file name as an argument and returns the unique ID contained within the file.
const std::string StoryFileReader::ExtractStoryIDFromFile(std::string fileName) const
{
	std::ifstream in(StoryFileReader::STORY_FILE_PATH + fileName);
	std::string line;
	bool IDFound;

	// This makes sure the file is readable.
	if (in.is_open())
	{
		while (std::getline(in, line))
		{
GetGame().GetDebugger().Print("StoryFileReader::ExtractStoryIDFromFile() - Line = : " + line, Debugger::PRIORITY::LOW);
			if (line != "")
			{
				if (line == "@")
				{
					std::getline(in, line);
					IDFound = true;
GetGame().GetDebugger().Print("StoryFileReader::ExtractStoryIDFromFile() - ID Found: " + line, Debugger::PRIORITY::LOW);
					break;
				}

			}
		}
		in.close();
	}
	else
	{
GetGame().GetDebugger().Print("StoryFileReader::ExtractStoryIDFromFile() - Cannot Read : " + fileName, Debugger::PRIORITY::TOP);
	}

	if (!IDFound)
	{
		line = DM::NO_STORY;
GetGame().GetDebugger().Print("StoryFileReader::ExtractStoryIDFromFile() - No ID Found: " + line, Debugger::PRIORITY::TOP);
	}

	return line;
}

// Grabs all of the files in the Story directory, weeding out other files that may be in there.
const std::vector<std::string> StoryFileReader::GetAllStoryFilesInDirectory() const
{
GetGame().GetDebugger().Print("StoryFileReader::GetAllStoryFilesInDirectory()...", Debugger::PRIORITY::MID);

	// Store for all found file names.
	std::vector<std::string> fileNames;

	// UGLY WINDOWS SHIT.
	WIN32_FIND_DATAA fileData;
	HANDLE hFind;

	// Note: this wasn't working until I added the "/*" to the directory.
	hFind = FindFirstFileA((StoryFileReader::STORY_FILE_PATH + "/*").c_str(), &fileData);

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
		} while (FindNextFileA(hFind, &fileData));
	}

	// Don't let the door hit you in the ass on your way out.
	FindClose(hFind);

// Print out all the file names found. Dubugging use only to make sure this works.
if (Debugger::DEBUG_MODE == Debugger::PRIORITY::LOW)
{
std::string	output = "There are ";
output.append(std::to_string(fileNames.size()));
output.append(" files in the folder, and they are..");

GetGame().GetDebugger().Print(output, Debugger::PRIORITY::LOW);

for (auto i : fileNames)
{
GetGame().GetDebugger().Print(i, Debugger::PRIORITY::LOW);
}
}

	return fileNames;
}

// Finds all of the story file in the default directory and returns a map of the story IDs and their respective file names.
const std::map<std::string, std::string> StoryFileReader::GetStoryFileNames() const
{
	// Get all of the names of the files in the default directory.
	std::vector<std::string> fileNames = GetAllStoryFilesInDirectory();

	// Create a map to hold everything. This gets copied to the master list stored elsewhere.
	std::map<std::string, std::string> storyFileNamesWithIDs;

	// Loop through all of the file names found and construct a map containing the story IDs and story file names.
	for (auto i : fileNames)
	{
		// Creates a pair object consisting of the id (extracted using the function ExtractStoryID...) and the file name and inserts it into the map.
		storyFileNamesWithIDs.insert(std::pair<std::string, std::string>(ExtractStoryIDFromFile(i), i));
	}

	return storyFileNamesWithIDs;
}