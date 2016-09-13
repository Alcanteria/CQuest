#pragma once

#include <string>
#include "Menu.h"

class Game;

class MainMenu : public Menu
{
public:
	MainMenu(Game& gameReference);
	~MainMenu();

	virtual void ValidateKeyPressed(std::string key) const override;
	virtual void ProcessOptionKeyPress(std::string key) const override;
};

