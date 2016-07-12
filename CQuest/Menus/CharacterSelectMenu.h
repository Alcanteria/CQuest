#pragma once

#include "Menu.h"
#include <vector>

class Game;

class CharacterSelectMenu : public Menu
{
public:
	CharacterSelectMenu(Game* game);
	~CharacterSelectMenu();

	virtual void ValidateKeyPressed(std::string key) const override;
	virtual void ProcessOptionKeyPress(std::string key) const override;

	const	void NameCharacter();
};

