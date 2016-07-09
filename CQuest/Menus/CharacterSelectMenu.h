#pragma once

#include "Menu.h"
#include <vector>

class Game;

class CharacterSelectMenu : public Menu
{
public:
	CharacterSelectMenu(Game* game);
	~CharacterSelectMenu();

	virtual void CheckKeyPressed(std::string key) const override;
	virtual void ProcessOptionKeyPress(std::string key) const override;
private:
	const void SetUpCharacterClasses();

	std::vector<std::string> characterClasses;
};

