#pragma once

#include <vector>
#include <string>

class Story
{
public:
	Story();
	~Story();

	const void WriteGameIntros();
	const void WriteCharacterSelectQuips();
	const void WriteNameSelectQuips();

	const std::vector<std::string>& GetIntros()						const	{ return *gameIntros; }
	const std::vector<std::string>& GetCharacterSelectQuips()		const	{ return *characterClassSelectionQuips; }
	const std::vector<std::string>& GetNameSelectQuips()			const	{ return *nameSelectionQuips; }

private:
	std::vector<std::string>* gameIntros;
	std::vector<std::string>* characterClassSelectionQuips;
	std::vector<std::string>* nameSelectionQuips;
};