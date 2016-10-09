#pragma once

#include <map>
#include <vector>
#include <string>

class Game;

class DM
{
public:
	DM(Game& gameReference);
	~DM();

	// Possible difficulties and their numerical values.
	enum DIFFICULTY {HARD = 80, MEDIUM = 50, EASY = 20};

/*	Special characters used to denote each section of story files. 
	These tell the program how to handle the next chunk of text. */
	enum FILE_FORMAT{ STORY_NAME = '!'};
	
	// Default value for when no story has been selected yet.
	const static std::string NO_STORY;

	// Location of the story files.
	const static std::string STORY_FILE_PATH;

	const			void										AddRest(int extraRest)										{ rest += extraRest; }
	const			void										AddTime(int extraTime)										{ timeLeft += extraTime; }
	const			void										GetAllStoryFilesInDirectory()				const;
	const			std::string&								GetCurrentStoryID()							const			{ return *currentStoryID; }
					Game&										GetGame()									const			{ return game; }
	const			int											GetRest()									const			{ return rest; }
	const			std::map<std::string, std::string>&			GetStoryDescriptions()						const			{ return *storyDescriptions; }
	const			std::map<std::string, std::string>&			GetStoryNames()								const			{ return *storyNames; }
	const			std::map<std::string, std::string>&			GetStoryFiles()								const			{ return *storyFiles; }
	const			int											GetTimeLeft()								const			{ return timeLeft; }
	const			void										RemoveRest(int restLost)									{ rest -= restLost; }
	const			void										ReadStoryFiles()							const;
	const			void										RemoveTime(int timeLost)									{ timeLeft -= timeLost; }
	const			void										SetCurrentStoryID(std::string newID)						{ *currentStoryID = newID; }


private:
	Game& game;

	int timeLeft = 24;
	int rest = 100;

	// Holds the information for the available stories to choose from.
	std::map<std::string, std::string>* storyNames;
	std::map<std::string, std::string>* storyDescriptions;
	std::map<std::string, std::string>* storyFiles;

	std::string* currentStoryID;
};

