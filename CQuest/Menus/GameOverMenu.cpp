#include "stdafx.h"
#include "GameOverMenu.h"


GameOverMenu::GameOverMenu(Game& gameReference) : Menu(gameReference)
{
	SetWelcomeMessage("*****GAME OVER*****");
}


GameOverMenu::~GameOverMenu()
{
}

void GameOverMenu::ValidateKeyPressed(std::string key) const
{

}

void GameOverMenu::ProcessOptionKeyPress(std::string key) const
{

}
