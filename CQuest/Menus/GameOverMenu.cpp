#include "stdafx.h"
#include "GameOverMenu.h"


GameOverMenu::GameOverMenu(Game* game) : Menu(game)
{
	SetWelcomeMessage("*****GAME OVER*****");
}


GameOverMenu::~GameOverMenu()
{
}

void GameOverMenu::CheckKeyPressed(std::string key) const
{

}

void GameOverMenu::ProcessOptionKeyPress(std::string key) const
{

}
