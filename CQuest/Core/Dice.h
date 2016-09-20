#pragma once
#include <time.h>
#include <stdlib.h>
#include <random>

class Game;

class Dice
{
public:
	Dice(Game& gameReference);
	~Dice();

					Game&	GetGame()							{ return game; }
	const			int		Roll(int lowest, int highest);

private:
	std::mt19937 rng;
	Game& game;
};

