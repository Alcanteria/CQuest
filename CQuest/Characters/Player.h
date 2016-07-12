#pragma once

#include "CharacterClass.h"
class Player
{
public:
	Player();
	~Player();

	const					CharacterClass* GetCharacter()						const					{ return playerCharacter; }
	const	void			CreateNewCharacter(CharacterClass* character);
	const	void			SetCharacterName(std::string name)											{ characterName = name; }
	const	std::string		GetCharacterName()									const					{ return characterName; }

private:
	CharacterClass* playerCharacter;

	std::string characterName;
};

