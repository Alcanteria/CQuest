#pragma once

#include <string>
#include "Menu.h"

class Game;

class MainMenu : public Menu
{
public:
	MainMenu(Game* game);
	~MainMenu();

	virtual void CheckKeyPressed(std::string key) const override;
	virtual void ProcessOptionKeyPress(std::string key) const override;
};

