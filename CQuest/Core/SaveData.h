#pragma once

#include <vector>

class Game;

class SaveData
{
public:
	SaveData(Game& gameReference);
	~SaveData();

	const static int			INTRO_ROLL_HISTORY_COUNT = 3;
	const static std::string	INTRO_SAVE_FILE_NAME;
	const static std::string	TEST_FILE_NAME;

	const		void					AddNewIntroRollToHistory(int roll)	const;
	const		bool					CheckIntroRoll(int roll);
	const		void					CreateDefaultIntroSaveFile()		const;
	const		void					GenerateRandomIntroValues()			const;
	const		Game&					GetGame()							const		{ return game; }
	const		std::vector<int>&		GetIntroRolls()						const		{ return *introRolls; }
	const		void					PrintIntroRollHistory()				const;
	const		void					ReadIntroSaveData()					const;
	const		void					SaveIntroData()						const;
	const		bool					VerifyIntroSaveData()				const;
	const		void					VerifySaveData()					const;
	const		void					VerifyTestData()					const;
	const		void					WriteTestFile()						const;

private:

	Game& game;
	std::vector<int>* introRolls;
};

