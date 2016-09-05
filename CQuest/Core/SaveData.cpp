#include "stdafx.h"
#include "SaveData.h"
#include <iostream>
#include <fstream>

const std::string SaveData::INTRO_SAVE_FILE_NAME = "C:\\Users\\Nick\\Desktop\\IntroSaveData.txt";

SaveData::SaveData()
{
	introRolls = new std::vector < int > ;
}


SaveData::~SaveData()
{
	delete introRolls;
}

const bool SaveData::CheckForIntroSaveData()
{
	std::ifstream file(SaveData::INTRO_SAVE_FILE_NAME.c_str());

	return file.good();
}