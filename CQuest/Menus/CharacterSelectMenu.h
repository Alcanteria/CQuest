#pragma once

#include "Menus\Menu.h"
#include <vector>

class Game;

class CharacterSelectMenu : public Menu
{
public:
	CharacterSelectMenu(Game* game);
	~CharacterSelectMenu();

	virtual void CheckKeyPressed(char key) const override;
	virtual void ProcessOptionKeyPress(char key) const override;
private:
	const void SetUpCharacterClasses();

	std::vector<std::string> characterClasses;
};

