#pragma once

#include <string>
#include "Menu.h"

class MainMenu : public Menu
{
public:
	MainMenu();
	~MainMenu();

	virtual void CheckKeyPressed(char key) const override;
	virtual void ProcessOptionKeyPress(char key) const override;
};

