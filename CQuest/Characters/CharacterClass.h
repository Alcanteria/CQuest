#pragma once

#include <string>

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
		WIZARD = 6,
		NUMBER_OF_CLASSES = 6
	};
	
	CharacterClass();
	~CharacterClass();

	const short GetSTR() const { return STR; }
	const short GetINT() const { return INT; }
	const short GetDEX() const { return DEX; }
	const short GetCHA() const { return CHA; }
	const short GetWIS() const { return WIS; }

	const short GetMaxHP()		const	{ return maxHP; }
	const short GetCurrentHP()	const	{ return currentHP; }
	const short GetAC()			const	{ return AC; }
	const void	SetAC(short newAC)		{ AC = newAC; }

	const		std::string GetName()			{ return name; }
	const void	SetName(std::string newName)	{ name = newName; }

	const		CharacterClass::CLASSES GetCharacterClass()				const	{ return characterClass; }
	const void	SetCharacterClass(CharacterClass::CLASSES newClass)				{ characterClass = newClass; }

	virtual bool Attack() = 0;
	virtual bool DealDamage() = 0;
	virtual bool TakeDamage() = 0;

private:

	// Base stats
	short STR;
	short INT;
	short DEX;
	short CHA;
	short WIS;

	short maxHP;
	short currentHP;
	short AC;

	std::string name;

	CharacterClass::CLASSES characterClass;
};

