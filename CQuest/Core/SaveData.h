#pragma once

#include <vector>

class SaveData
{
public:
	SaveData();
	~SaveData();

	const static int INTRO_ROLL_COUNT = 3;
	const static std::string INTRO_SAVE_FILE_NAME;

	const bool CheckIntroRoll(int roll);
	const bool CheckForIntroSaveData();
private:
	std::vector<int>* introRolls;
};

