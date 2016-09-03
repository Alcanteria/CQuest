#include "stdafx.h"
#include "Dice.h"



Dice::Dice()
{
	rng.seed(std::random_device()());
}


Dice::~Dice()
{
}

// Returns a random number from the lowest number supplied to the highest.
const int Dice::Roll(int lowest, int highest)
{
	std::uniform_int_distribution<std::mt19937::result_type> dist6(lowest, highest);

	return dist6(rng);
}