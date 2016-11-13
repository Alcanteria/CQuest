#pragma once

#include <string>
#include <map>
#include <vector>
#include "Setting\Story.h"

class Game;

class StoryFileReader
{
public:
	StoryFileReader(Game& gameReference);
	~StoryFileReader();

	// Location of the story files.
	const static std::string STORY_FILE_PATH;

	/*	Special characters used to denote each section of story files.
	These tell the program how to handle the next chunk of text. */
	const static std::string FLAG_STORY_ID;
	const static std::string FLAG_STORY_NAME;
	const static std::string FLAG_STORY_DESCRIPTION;
	const static std::string FLAG_CHAPTER;
	const static std::string FLAG_CHOICES;
	const static std::string FLAG_RESULTS;
	const static std::string FLAG_STAT_CHANGES;


	const			std::map<std::string, std::string>			CreateMapForStoryAttribute(std::string attribute)							const;
	const			std::string									ExtractStoryIDFromFile(std::string fileName)								const;
	const			std::string									ExtractStoryNameFromFile(std::string fileName)								const;
					void										GetAllStoryFilesInDirectory();
					Game&										GetGame()																	const		{ return game; }
	const			std::map<std::string, std::string>			GetStoryDescriptions()														const;
	const			std::map<std::string, std::string>			GetStoryFileNames()															const;
	const			std::map<std::string, std::string>			GetStoryNames()																const;
					void										LoadChapterFromFile(Story& story, std::ifstream& in, std::string& line)		const;
					void										LoadStoryFromFile(Story& story, std::string fileName)						const;
	const			std::string									SearchFileForAttribute(std::string fileName, std::string attribute)			const;

private:
	Game& game;

	std::vector<std::string> fileNames;
};

