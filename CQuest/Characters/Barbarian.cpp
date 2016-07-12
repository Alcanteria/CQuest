#include "stdafx.h"
#include "Barbarian.h"


Barbarian::Barbarian()
{
	SetCharacterClass(CharacterClass::CLASSES::BARBARIAN);

	SetName("Barbarian");

	SetSTR(20);
	SetCON(18);
	SetDEX(16);
	SetWIS(14);
	SetCHA(12);
	SetINT(10);

}


Barbarian::~Barbarian()
{
}
