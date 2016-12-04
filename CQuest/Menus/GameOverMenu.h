#pragma once

#include "Menu.h"

class Game;

class GameOverMenu : public Menu
{
public:
	GameOverMenu(Game& gameReference);
	~GameOverMenu();

	virtual void ValidateKeyPressed(std::string key)			override;
	virtual void ProcessOptionKeyPress(std::string key)			override;
};

