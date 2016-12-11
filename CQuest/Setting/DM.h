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
					std::vector<std::string>&					GetIntros()										const			{ return *gameIntros; }
	const			int											GetNewIntroDiceRoll()							const;
	const			std::string									GetRandomIntro()								const;
	const			int											GetRest()										const			{ return rest; }
	const			Story&										GetStory()										const			{ return *story; }
	const			std::map<std::string, std::string>&			GetStoryDescriptions()							const			{ return *storyDescriptions; }
	const			std::map<std::string, std::string>&			GetStoryNames()									const			{ return *storyNames; }
	const			std::map<std::string, std::string>&			GetStoryFileNames()								const			{ return *storyFileNames; }
	const			int											GetTimeLeft()									const			{ return timeLeft; }
					void										Initialize()									const;
					void										LoadNewStory(std::string storyID);
					void										RemoveRest(int restLost)										{ rest -= restLost; }
					void										RemoveTime(int timeLost)										{ timeLeft -= timeLost; }
					void										SetCurrentStoryID(std::string newID)							{ *currentStoryID = newID; }

private:
	std::string* currentStoryID;

	Game& game;

	// Flavor text to display at the start of the program.
	std::vector<std::string>* gameIntros;

	// This value determines the chances for success in most parts of the game.
	int rest = 100;

	// Stores the story chose by the player.
	Story* story;

	// Stores information on every available story.
	std::map<std::string, std::string>* storyDescriptions;
	std::map<std::string, std::string>* storyFileNames;
	StoryFileReader*					storyFileReader;
	std::map<std::string, std::string>* storyNames;

	// In-Game time that is used to determine which parts of the story are used. This is NOT updated in real-time.
	int timeLeft = 24;
};

