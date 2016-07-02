#include "stdafx.h"
#include "MainMenu.h"


MainMenu::MainMenu()
{
	welcomeMessage = "Welcome To CQuest.";
}


MainMenu::~MainMenu()
{
}

void MainMenu::SetActiveStatus(bool status)
{
	isActive = status;
}

bool MainMenu::IsActive() const
{
	return isActive;
}
