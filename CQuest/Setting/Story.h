#pragma once

#include <vector>
#include <string>

class Game;

class Story
{
public:
	Story(Game& gameReference);
	~Story();

	const	std::vector<std::string>&	GetCharacterSelectQuips()		const	{ return *characterClassSelectionQuips; }
			Game&						GetGame()						const	{ return game; }
	const	int							GetNewIntroDiceRoll()			const;
	const	std::vector<std::string>&	GetIntros()						const	{ return *gameIntros; }
	const	std::vector<std::string>&	GetNameSelectQuips()			const	{ return *nameSelectionQuips; }
	const	std::string					GetRandomIntro()				const;
	const	void						WriteCharacterSelectQuips()		const;
	const	void						WriteGameIntros()				const;
	const	void						WriteNameSelectQuips()			const;

private:
	std::vector<std::string>* characterClassSelectionQuips;
	std::vector<std::string>* gameIntros;
	std::vector<std::string>* nameSelectionQuips;

	Game& game;
};