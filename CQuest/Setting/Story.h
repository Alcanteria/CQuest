#pragma once

#include <vector>
#include <string>

class Game;

class Story
{
public:
	Story(Game& gameReference);
	~Story();

			Game&						GetGame()						const	{ return game; }

private:

	Game& game;
};