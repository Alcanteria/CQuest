#include "stdafx.h"
#include "GameOverMenu.h"
#include "Core\Game.h"


GameOverMenu::GameOverMenu(Game& gameReference) : Menu(gameReference)
{
	SetWelcomeMessage("*****GAME OVER*****");
}


GameOverMenu::~GameOverMenu()
{
Debug::Print("GameOverMenu() Destructor.", Debug::PRIORITY::LOW);
}

void GameOverMenu::ValidateKeyPressed(std::string key)
{

}

void GameOverMenu::ProcessOptionKeyPress(std::string key)
{

}
