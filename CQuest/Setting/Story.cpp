#include "stdafx.h"
#include "Story.h"
#include "Core\Game.h"


Story::Story(Game& gameReference) : game(gameReference)
{
}


Story::~Story()
{
Tools::Debug::Print("Story() Destructor.", Tools::Debug::PRIORITY::LOW);
}

/*
****Adds a new chapter to the chapter vector and creates a new chapter menu.
*/
void Story::AddChapter(Chapter newChapter)
{
	chapters.push_back(newChapter);
}