#include "stdafx.h"
#include "GameOverMenu.h"
#include "Core\Game.h"


GameOverMenu::GameOverMenu(Game& gameReference) : Menu(gameReference)
{
	SetWelcomeMessage("*****GAME OVER*****");
}


GameOverMenu::~GameOverMenu()
{
	GetGame().GetDebugger().Print("GameOverMenu() Destructor.");
}

void GameOverMenu::ValidateKeyPressed(std::string key) const
{

}

void GameOverMenu::ProcessOptionKeyPress(std::string key) const
{

}
