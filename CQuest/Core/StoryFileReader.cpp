#include "stdafx.h"
#include "StoryFileReader.h"
#include "Core\Game.h"
#include <fstream>
#include "Setting\Chapter.h"

// Location of the story files.
const std::string StoryFileReader::STORY_FILE_PATH = "Data\\Stories\\";

// Speical character flags used in reading story file attributes.
const std::string StoryFileReader::FLAG_STORY_ID				= "@@@@STORY_ID";
const std::string StoryFileReader::FLAG_STORY_NAME				= "@@@@STORY_NAME";
const std::string StoryFileReader::FLAG_STORY_DESCRIPTION		= "@@@@STORY_DESCRIPTION";
const std::string StoryFileReader::FLAG_CHAPTER					= "########CHAPTER";
const std::string StoryFileReader::FLAG_CHOICES					= "####CHOICES";
const std::string StoryFileReader::FLAG_RESULTS					= "####RESULTS";
const std::string StoryFileReader::FLAG_STAT_CHANGES			= "####STAT_CHANGES";

StoryFileReader::StoryFileReader(Game& gameReference) : game(gameReference)
{
	GetAllStoryFilesInDirectory();
}


StoryFileReader::~StoryFileReader()
{
}

/* 
****Returns a map of the containing the unique ID and desired attribute supplied from the supplied file name. 
*/
const std::map<std::string, std::string> StoryFileReader::CreateMapForStoryAttribute(std::string attribute) const
{
	// Create a place holder map to store everything. This will be returned and copied to the master map.
	std::map<std::string, std::string> map;

	for (auto i : fileNames)
	{
		// Creates a pair object consisting of the unique ID of the file and the supplied attribute, then inserts the pair into the map.
		map.insert(std::pair<std::string, std::string>(SearchFileForAttribute(i, StoryFileReader::FLAG_STORY_ID), SearchFileForAttribute(i, attribute)));
	}

	return map;
}

/* 
****Take a file name as an argument and returns the unique ID contained within the file.
*/
const std::string StoryFileReader::ExtractStoryIDFromFile(std::string fileName) const
{
	return SearchFileForAttribute(fileName, StoryFileReader::FLAG_STORY_ID);
}

/* 
****Take a file name as an argument and returns the story name contained within the file.
*/
const std::string StoryFileReader::ExtractStoryNameFromFile(std::string fileName) const
{
	return SearchFileForAttribute(fileName, StoryFileReader::FLAG_STORY_NAME);
}

/* 
****Grabs all of the files in the Story directory, weeding out other files that may be in there.
*/
void StoryFileReader::GetAllStoryFilesInDirectory()
{
Debug::Print("StoryFileReader::GetAllStoryFilesInDirectory()...", Debug::PRIORITY::MID);

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
if (Debug::DEBUG_MODE == Debug::PRIORITY::LOW)
{
std::string	output = "There are ";
output.append(std::to_string(fileNames.size()));
output.append(" files in the folder, and they are..");

Debug::Print(output, Debug::PRIORITY::LOW);

for (auto i : fileNames)
{
Debug::Print(i, Debug::PRIORITY::LOW);
}
}
}

/* 
****Finds all of the story files in the default directory and returns a map of the story IDs and their respective descriptions.
*/
const std::map<std::string, std::string> StoryFileReader::GetStoryDescriptions() const
{
	return CreateMapForStoryAttribute(StoryFileReader::FLAG_STORY_DESCRIPTION);
}

/* 
****Finds all of the story files in the default directory and returns a map of the story IDs and their respective file names.
*/
const std::map<std::string, std::string> StoryFileReader::GetStoryFileNames() const
{
	// Create a map to hold everything. This gets returned and copied to the master list stored elsewhere.
	std::map<std::string, std::string> storyFileNamesWithIDs;

	// Loop through all of the file names found and construct a map containing the story IDs and story file names.
	for (auto i : fileNames)
	{
		// Creates a pair object consisting of the id (extracted using the function ExtractStoryID...) and the file name and inserts it into the map.
		storyFileNamesWithIDs.insert(std::pair<std::string, std::string>(ExtractStoryIDFromFile(i), i));
	}

	return storyFileNamesWithIDs;
}

/* 
****Finds all of the story files in the default directory and returns a map of the story IDs and their respective file names.
*/
const std::map<std::string, std::string> StoryFileReader::GetStoryNames() const
{
	return CreateMapForStoryAttribute(StoryFileReader::FLAG_STORY_NAME);
}

/*
****Creates a chapter object and copies it into the passed story object using the file stream passed.
*/
void StoryFileReader::LoadChapterFromFile(Story& story, std::ifstream& in, std::string& line) const
{
Debug::Print("StoryFileReader::LoadChapterFromFile() - Reading Chapter...", Debug::PRIORITY::MID);
	// Place holder chapter object to store everything read from file.
	Chapter chapter;

Debug::Print("StoryFileReader::LoadChapterFromFile() - Description: " + line, Debug::PRIORITY::MID);
	// The line object passed in is already on the description portion of the file, so copy that to the chapter object now.
	chapter.CopyDescriptionsFromFile(line);

	// Move to the next line in the file.
	std::getline(in, line);

	// We are only focusing on this ONE chapter section. We will exit out when it's done.
	while (line != StoryFileReader::FLAG_CHAPTER)
	{
		// Skip blank lines.
		if (line != "")
		{
			// Load choices.
			if (line == StoryFileReader::FLAG_CHOICES)
			{
Debug::Print("StoryFileReader::LoadChapterFromFile() - Choices Found", Debug::PRIORITY::MID);
				// Move to the next line in the file.
				std::getline(in, line);

				// Create a placeholder for the choices.
				std::vector<std::string> choices;

				// Keep looping through all of the choices.
				while (line != StoryFileReader::FLAG_CHOICES)
				{
Debug::Print("StoryFileReader::LoadChapterFromFile() - Choice: " + line, Debug::PRIORITY::MID);
					choices.push_back(line);

					// Move to the next line in the file.
					std::getline(in, line);
				}

				// Copy placeholder to the chapter.
				chapter.CopyChoicesFromFile(choices);

				// Move to the next line in the file.
				std::getline(in, line);
			}

			// Load Results.
			if (line == StoryFileReader::FLAG_RESULTS)
			{
Debug::Print("StoryFileReader::LoadChapterFromFile() - Results Found", Debug::PRIORITY::MID);
				// Move to the next line in the file.
				std::getline(in, line);

				// Create a placeholder for the results.
				std::vector<std::string> results;

				// Keep looping through all of the results.
				while (line != StoryFileReader::FLAG_RESULTS)
				{
Debug::Print("StoryFileReader::LoadChapterFromFile() - Result: " + line, Debug::PRIORITY::MID);
					results.push_back(line);

					// Move to the next line in the file.
					std::getline(in, line);
				}

				// Copy placeholder to the chapter.
				chapter.CopyResultsFromFile(results);

				// Move to the next line in the file.
				std::getline(in, line);
			}

			// Load stat changes
			if (line == StoryFileReader::FLAG_STAT_CHANGES)
			{
Debug::Print("StoryFileReader::LoadChapterFromFile() - Stat Changes Found", Debug::PRIORITY::MID);
				// Move to the next line in the file.
				std::getline(in, line);

				// Create a placeholder for the stat changes.
				std::vector<short> statChanges;

				// Keep looping through all of the stat changes.
				while (line != StoryFileReader::FLAG_STAT_CHANGES)
				{
Debug::Print("StoryFileReader::LoadChapterFromFile() - Stat Change: " + line, Debug::PRIORITY::MID);
					/* We are converting the read string into an int and forcing it into a short.
					We SHOULD be making sure it fits the short range, but it's just me so I know the score.*/
					statChanges.push_back(std::stoi(line));

					// Move to the next line in the file.
					std::getline(in, line);
				}

				// Copy the placeholder to the chapter.
				chapter.CopyStatChangesFromFile(statChanges);
			}

			// Move to the next line in the file.
			std::getline(in, line);
		}
	}

	story.AddChapter(chapter);
Debug::Print("StoryFileReader::LoadChapterFromFile() - Chapter added to story.", Debug::PRIORITY::MID);
}

/*
****Reads the passed story file and stores the information into the passed story object.
*/
void StoryFileReader::LoadStoryFromFile(Story& story, std::string fileName) const
{
	std::ifstream* in = new std::ifstream(StoryFileReader::STORY_FILE_PATH + fileName);
	std::string* line = new std::string;

	// This makes sure the file is readable.
	if (in->is_open())
	{
		// While there is still stuff in the file...
		while (std::getline(*in, *line))
		{
			// Skip blank lines...
			if (*line != "")
			{
				// Look for the character to signal the presence of a chapter
				if (*line == StoryFileReader::FLAG_CHAPTER)
				{
					// Jump down to the next line which is the start of the chapter
					std::getline(*in, *line);
					
Debug::Print("StoryFileReader::LoadStoryFromFile() - Chapter Found", Debug::PRIORITY::MID);

					LoadChapterFromFile(story, *in, *line);
				}
			}
		}
		in->close();
	}
	else
	{
Debug::Print("StoryFileReader::LoadStoryFromFile() - Cannot Read : " + fileName, Debug::PRIORITY::TOP);
	}

	delete	in;
			in = nullptr;
	delete	line;
			line = nullptr;
}

/* 
****Looks through the supplied file name to find the supplied attribute. Return the line proceeding the attribute.
*/
const std::string StoryFileReader::SearchFileForAttribute(std::string fileName, std::string attribute) const
{
	std::ifstream in(StoryFileReader::STORY_FILE_PATH + fileName);
	std::string line;
	bool IDFound;

	// This makes sure the file is readable.
	if (in.is_open())
	{
		// While there is still stuff in the file...
		while (std::getline(in, line))
		{
Debug::Print("StoryFileReader::SearchFileForAttribute() - Line = : " + line, Debug::PRIORITY::LOW);

			// Skip blank lines...
			if (line != "")
			{
				// Look for the character to signal the presence of the attribute...
				if (line == attribute)
				{
					// Jump down to the next line which actually contains the attribute.
					std::getline(in, line);

					IDFound = true;
Debug::Print("StoryFileReader::SearchFileForAttribute() - Attribute " + attribute + " Found: " + line, Debug::PRIORITY::LOW);
					break;
				}
			}
		}
		in.close();
	}
	else
	{
Debug::Print("StoryFileReader::SearchFileForAttribute() - Cannot Read : " + fileName, Debug::PRIORITY::TOP);
	}

	if (!IDFound)
	{
		line = DM::NO_STORY;
Debug::Print("StoryFileReader::SearchFileForAttribute() - No ID Found: " + line, Debug::PRIORITY::TOP);
	}

	return line;
}