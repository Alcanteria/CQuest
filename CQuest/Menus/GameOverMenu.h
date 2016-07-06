#pragma once

#include "Menu.h"

class Game;

class GameOverMenu : public Menu
{
public:
	GameOverMenu(Game* game);
	~GameOverMenu();

	virtual void CheckKeyPressed(char key) const override;
	virtual void ProcessOptionKeyPress(char key) const override;
};

