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
				void					CreateDefaultIntroSaveFile();
				void					GenerateRandomIntroValues();
				Game&					GetGame()										{ return game; }
	const		std::vector<int>&		GetIntroRolls()						const		{ return *introRolls; }
				void					PrintIntroRollHistory()				const;
				void					ReadIntroRollHistory();
				void					ReadIntroStoryText();
				void					SaveIntroData()						const;
	const		bool					VerifyIntroSaveData()				const;
				void					VerifySaveData();
				void					VerifyTestData();
				void					WriteTestFile();

private:

	Game& game;
	std::vector<int>*	introRolls;
};

