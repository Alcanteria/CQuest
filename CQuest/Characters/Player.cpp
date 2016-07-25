#include "stdafx.h"
#include "Player.h"


Player::Player()
{
}


Player::~Player()
{
	delete playerCharacter;
}

// Creates a new character class for the player.
const void Player::CreateNewCharacter(CharacterClass* character)
{
	playerCharacter = character;
}