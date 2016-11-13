#pragma once

#include <string>
#include <vector>

class Chapter
{
public:
	Chapter();
	~Chapter();

				void							CopyChoicesFromFile(std::vector<std::string> newChoices)					{ choices = newChoices; }
				void							CopyDescriptionsFromFile(std::string newDescription)						{ description = newDescription; }
				void							CopyResultsFromFile(std::vector<std::string> newResults)					{ results = newResults; }
				void							CopyStatChangesFromFile(std::vector<short> changes)							{ statChanges = changes; }
	const		std::vector<std::string>		GetChoices()													const		{ return choices; }
	const		std::string						GetDescription()												const		{ return description; }
	const		std::vector<std::string>		GetResults()													const		{ return results; }
	const		std::vector<short>				GetStatChanges()												const		{ return statChanges; }

private:
	std::vector<std::string>	choices;
	std::string					description;
	std::vector<std::string>	results;
	std::vector<short>			statChanges;
};

