#pragma once

#include <string>
#include <map>
#include <vector>

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
	enum FILE_FORMAT{ STORY_ID = '@', STORY_NAME = '!' };


	const			std::string									ExtractStoryIDFromFile(std::string fileName)	const;
	const			std::vector<std::string>					GetAllStoryFilesInDirectory()					const;
					Game&										GetGame()										const		{ return game; }
	const			std::map<std::string, std::string>			GetStoryFileNames()								const;
					void										ReadStoryFiles()								const;

private:
	Game& game;
};

