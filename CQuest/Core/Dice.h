#pragma once
#include <time.h>
#include <stdlib.h>
#include <random>
class Dice
{
public:
	Dice();
	~Dice();

	const static int NUMBER_OF_INTROS = 5;

	const int Roll(int lowest, int highest);

private:
	std::mt19937 rng;
};

