#pragma once

#include <string>
#include "Menu.h"

class Game;

class MainMenu : public Menu
{
public:
	MainMenu(Game* game);
	~MainMenu();

	virtual void CheckKeyPressed(char key) const override;
	virtual void ProcessOptionKeyPress(char key) const override;
};

