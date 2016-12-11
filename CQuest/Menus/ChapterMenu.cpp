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

void ChapterMenu::ProcessOptionKeyPress(std::string key)
{
	// Convert the input to an int.
	unsigned int keyAsInt = std::stoi(key);

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
	if (keyAsInt == optionKeys.size())
	{
		GetGame().EndGame();
	}
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