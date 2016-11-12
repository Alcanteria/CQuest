#pragma once

#include <map>
#include <vector>
#include <string>
#include "Core\StoryFileReader.h"

class Game;

class DM
{
public:
	DM(Game& gameReference);
	~DM();

	// Possible difficulties and their numerical values.
	enum DIFFICULTY {HARD = 80, MEDIUM = 50, EASY = 20};
	
	// Default value for when no story has been selected yet.
	const static std::string NO_STORY;

					void										AddRest(int extraRest)											{ rest += extraRest; }
					void										AddTime(int extraTime)											{ timeLeft += extraTime; }
	const			std::string&								GetCurrentStoryID()								const			{ return *currentStoryID; }
					Game&										GetGame()										const			{ return game; }
	const			int											GetRest()										const			{ return rest; }
	const			std::map<std::string, std::string>&			GetStoryDescriptions()							const			{ return *storyDescriptions; }
	const			std::map<std::string, std::string>&			GetStoryNames()									const			{ return *storyNames; }
	const			std::map<std::string, std::string>&			GetStoryFileNames()								const			{ return *storyFileNames; }
	const			int											GetTimeLeft()									const			{ return timeLeft; }
					void										Initialize()									const;
					void										RemoveRest(int restLost)										{ rest -= restLost; }
					void										RemoveTime(int timeLost)										{ timeLeft -= timeLost; }
					void										SetCurrentStoryID(std::string newID)							{ *currentStoryID = newID; }

private:
	Game& game;

	// In-Game time that is used to determine which parts of the story are used. This is NOT updated in real-time.
	int timeLeft = 24;

	// This value determines the chances for success in most parts of the game.
	int rest = 100;

	// Holds the information for the available stories to choose from.
	std::map<std::string, std::string>* storyNames;
	std::map<std::string, std::string>* storyDescriptions;
	std::map<std::string, std::string>* storyFileNames;

	std::string* currentStoryID;

	StoryFileReader* storyFileReader;
};

