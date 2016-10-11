#pragma once

#include <vector>

class Game;

class SaveData
{
public:
	SaveData(Game& gameReference);
	~SaveData();

	const	static	int			INTRO_ROLL_HISTORY_COUNT = 3;
	const	static	std::string	INTRO_ROLL_HISTORY_FILENAME;
	const	static	std::string	INTRO_STORY_TEXT_FILENAME;
	const	static	std::string	TEST_FILE_NAME;

				void					AddNewIntroRollToHistory(int roll)	const;
	const		bool					CheckIntroRoll(int roll);
				void					CreateDefaultIntroSaveFile()		const;
				void					GenerateRandomIntroValues()			const;
	const		Game&					GetGame()							const		{ return game; }
	const		std::vector<int>&		GetIntroRolls()						const		{ return *introRolls; }
				void					PrintIntroRollHistory()				const;
				void					ReadIntroRollHistory()				const;
				void					ReadIntroStoryText()				const;
				void					SaveIntroData()						const;
	const		bool					VerifyIntroSaveData()				const;
				void					VerifySaveData()					const;
				void					VerifyTestData()					const;
				void					WriteTestFile()						const;

private:

	Game& game;
	std::vector<int>*	introRolls;
};

