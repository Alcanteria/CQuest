#include "stdafx.h"
#include "Story.h"
#include "Core\Game.h"


Story::Story(Game& gameReference) : game(gameReference)
{
}


Story::~Story()
{

GetGame().GetDebugger().Print("Story() Destructor.", Debugger::PRIORITY::LOW);
}