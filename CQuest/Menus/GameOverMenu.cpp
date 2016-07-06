#include "stdafx.h"
#include "GameOverMenu.h"


GameOverMenu::GameOverMenu(Game* game) : Menu(game)
{
	SetWelcomeMessage("*****GAME OVER*****");
}


GameOverMenu::~GameOverMenu()
{
}

void GameOverMenu::CheckKeyPressed(char key) const
{

}

void GameOverMenu::ProcessOptionKeyPress(char key) const
{

}
