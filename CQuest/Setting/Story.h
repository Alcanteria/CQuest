#pragma once

#include <vector>
#include <string>

class Story
{
public:
	Story();
	~Story();

	const void WriteGameIntros()			const;
	const void WriteCharacterSelectQuips()	const;
	const void WriteNameSelectQuips()		const;

private:
	std::vector<std::string> gameIntros;
	std::vector<std::string> characterClassSelectionQuips;
	std::vector<std::string> nameSelectionQuips;
};

