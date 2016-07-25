#pragma once

#include "Menu.h"

class Game;

class GameOverMenu : public Menu
{
public:
	GameOverMenu(Game* game);
	~GameOverMenu();

	virtual void ValidateKeyPressed(std::string key) const override;
	virtual void ProcessOptionKeyPress(std::string key) const override;
};

