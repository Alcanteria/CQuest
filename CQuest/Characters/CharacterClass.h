#pragma once
class CharacterClass
{
public:

	enum CLASSES {
		NONE = 0,
		BARBARIAN = 1,
		CLERIC = 2,
		FIGHTER = 3,
		RANGER = 4,
		ROGUE = 5,
		WIZARD = 6
	};
	
	CharacterClass();
	~CharacterClass();
};

