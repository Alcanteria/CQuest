#include "stdafx.h"
#include "Story.h"
#include "Core\Game.h"


Story::Story(Game& gameReference) : game(gameReference)
{
}


Story::~Story()
{

Debug::Print("Story() Destructor.", Debug::PRIORITY::LOW);
}