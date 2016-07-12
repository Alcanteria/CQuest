#pragma once

#include <string>
#include <vector>

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

	const static std::vector<std::string> CLASS_NAMES;
	
	CharacterClass();
	~CharacterClass();

	const short GetSTR() const { return STR; }
	const short GetINT() const { return INT; }
	const short GetDEX() const { return DEX; }
	const short GetCON() const { return CON; }
	const short GetCHA() const { return CHA; }
	const short GetWIS() const { return WIS; }

	const void SetSTR(short str) { STR = str; }
	const void SetINT(short inl) { INT = inl; }
	const void SetDEX(short dex) { DEX = dex; }
	const void SetCON(short con) { CON = con; }
	const void SetCHA(short cha) { CHA = cha; }
	const void SetWIS(short wis) { WIS = wis; }

	const short GetMaxHP()		const	{ return maxHP; }
	const short GetCurrentHP()	const	{ return currentHP; }
	const short GetAC()			const	{ return AC; }
	const void	SetAC(short newAC)		{ AC = newAC; }

	const		CharacterClass::CLASSES GetCharacterClass()				const	{ return characterClass; }
	const void	SetCharacterClass(CharacterClass::CLASSES newClass)				{ characterClass = newClass; }

	// These will be the pure virtual methods that will be implemented in the child classes.
	//virtual bool Attack() = 0;
	//virtual bool DealDamage() = 0;
	//virtual bool TakeDamage() = 0;

protected:

	// Base stats
	short STR;
	short INT;
	short DEX;
	short CON;
	short CHA;
	short WIS;

	short maxHP;
	short currentHP;
	short AC;

private:

	CharacterClass::CLASSES characterClass;
};