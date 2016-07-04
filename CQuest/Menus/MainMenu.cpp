#include "stdafx.h"
#include "MainMenu.h"


MainMenu::MainMenu()
{
	welcomeMessage = "**********Welcome To CQuest.**********";

	AddOptionKey('1', "Start New Game.");
	AddOptionKey('2', "Exit.");
}


MainMenu::~MainMenu()
{
}
