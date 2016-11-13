#pragma once

#include <vector>
#include <string>
#include "Setting\Chapter.h"

class Game;

class Story
{
public:
	Story(Game& gameReference);
	~Story();

			void						AddChapter(Chapter newChapter)							{ chapters.push_back(newChapter); }
	const	short						GetChapterIndex()								const	{ return chapterIndex; }
	const	Chapter&					GetCurrentChapter()								const	{ return chapters.at(chapterIndex); }
			Game&						GetGame()										const	{ return game; }
			void						GoToChapter(short chapter)								{ chapterIndex = chapter; }
			void						NextChapter()											{ chapterIndex++; }
			void						PreviousChapter()										{ chapterIndex--; }

private:
	std::vector<Chapter> chapters;
	short chapterIndex = 0;
	Game& game;
};