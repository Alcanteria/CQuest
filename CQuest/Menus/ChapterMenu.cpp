#include "stdafx.h"
#include "ChapterMenu.h"
#include "Core\Game.h"
#include <iostream>

ChapterMenu::ChapterMenu(Game& gameReference, Chapter newChapter) : Menu(gameReference), chapter(newChapter)
{
}


ChapterMenu::~ChapterMenu()
{
}

/*
****Goes through all of the available story progression choices and adds them as menu options.
*/
void ChapterMenu::AddStoryOptions()
{
Tools::Debug::Print("ChapterMenu::AddStoryOptions()", Tools::Debug::PRIORITY::LOW);

	/*	Keep track of which iteration of the below for loop we are on. We are starting at one because
		we are copying this number into the AddOptionKey() function as the number the user needs to 
		press to select it and we aren't using zero as an option. 
		(Easily the longest comment ever written for a single integer)*/
	int iteration = 1;

	for (auto i : chapter.GetChoices())
	{
		AddOptionKey(std::to_string(iteration), i);
		iteration++;
	}

	// Add the "Exit" buttons to the end of the option key list.
	AddOptionKey(std::to_string(iteration), Menu::EXIT);
}

/*
****Changes all of the current chapter values to the next chapter in the story.
*/
void ChapterMenu::ChangeChapter(Chapter newChapter)
{
	RemoveOptionKeys();
	chapter = newChapter;
	Initialize();
}

/*
****Perform actions to prepare this menu for player use.
*/
void ChapterMenu::Initialize()
{
Tools::Debug::Print("ChapterMenu::Initialize()", Tools::Debug::PRIORITY::LOW);

	welcomeMessage = chapter.GetDescription();
	AddStoryOptions();
}

/*
****Takes the story choice the user made and adjust the game state appropriately.
*/
void ChapterMenu::ProcessChoice(unsigned int key)
{
Tools::Debug::Print("ChapterMenu::ProcessOptionKeyPress() - Story option selected.", Tools::Debug::PRIORITY::MID);
	
	/*	The values to change the player stats are stored in a vector. Since there are two values to retrieve for each choice
		(time lost and rest lost) we need to find which two values in the vector are the ones that correspond with the story 
		choice the user made.
		
		The values are stored sequentially from the results for the first option to the results for the last option. So if
		there are three options for the player to choose from, there are six values in the vector (0-5). These results are
		in pairs of two. The first being time lost and the second being rest lost. For example:
		
		Choosing option 1 would mean the values are at 0 and 1.
		Choosing option 2 would mean the values are at 2 and 3.
		Choosing option 3 would mean the values are at 4 and 5.
		
		I figured out a simple equation that will automatically find the vector index for the first value we need. After
		which we just increment by 1 to get the next value in the pair.
		
		firstValue = (choice - 1) + (choice - 1)
	*/

	// Find the vector indices we need.
	int timeLocation = (key - 1) + (key - 1);
	int restLocation = timeLocation + 1;

	// Grab the values in the vector AT the indices.
	short timeLost = chapter.GetStatChanges().at(timeLocation);
	short restLost = chapter.GetStatChanges().at(restLocation);

	// Subtract those values from the player's stats.
	GetGame().GetDM().RemoveTime(timeLost);
	GetGame().GetDM().RemoveRest(restLost);

	// Check if the game has ended due to stats dropping to zero.
	if (GetGame().GetDM().IsGameOver())
		GetGame().EndGame();
}

void ChapterMenu::ProcessOptionKeyPress(std::string key)
{
	// Convert the input to an int.
	unsigned int keyAsInt = std::stoi(key);

	// Check if the exit key was pressed.
	if (keyAsInt == optionKeys.size())
	{
		GetGame().EndGame();
	}

	// Check if a story option was selected.
	if (keyAsInt < optionKeys.size() && keyAsInt >= 0)
	{
		ProcessChoice(keyAsInt);
		GetGame().GetDM().GoToNextChapter();
		ChangeChapter(GetGame().GetDM().GetStory().GetCurrentChapter());
	}

	// Was having issues doing this as a switch so I had to do the key checking with an ugly else if block.
	/*if (keyAsInt <= storyIDs.size() && keyAsInt >= 0)
	{
		Tools::Debug::Print("Story Selected.", Tools::Debug::PRIORITY::LOW);

		GetGame().GetDM().LoadNewStory(storyIDs.at(keyAsInt - 1));
	}
	else if (keyAsInt == storyIDs.size() + 1)
		GetGame().GoBackToPreviousMenu();
	else if (keyAsInt == storyIDs.size() + 2)
		GetGame().EndGame();*/
}

void ChapterMenu::ValidateKeyPressed(std::string key)
{
	if (IsOptionKeyPresent(key))
	{
		ProcessOptionKeyPress(key);
	}
	else
	{
		std::cout << "Not a valid option. Please try again." << std::endl;
	}
}