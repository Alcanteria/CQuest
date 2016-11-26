#pragma once

#include <string>
#include <map>
#include <vector>

class Game;

class Menu
{

public:
	Menu(Game& gameReference);
	~Menu();

	// List of possible menus.
	enum MENUS { MAIN, CHARACTER_SELECT, GAME_OVER, STORY_SELECT, NONE };

	// Default exit menu value.
	const std::string EXIT = "*****EXIT*****";

	// Default "back to previous menu" value.
	const std::string GO_BACK = "<----GO BACK";

			void									AddOptionKey(std::string key, std::string description);
			Game&									GetGame()													const		{ return game; }
	const	std::map<std::string, std::string>		GetOptionKeys()												const		{ return optionKeys; }
	const	std::string								GetWelcomeMessage()											const		{ return welcomeMessage; }
	const	bool									IsActive()													const		{ return isActive; }
	const	bool									IsOptionKeyPresent(std::string key)							const;
	static	void							PrintChunk();
	static	void							PrintGap(int spaces = 3);
			void									PrintInvalidOption()										const;
	static	void							PrintSeperator();
	virtual	void									ProcessOptionKeyPress(std::string key)						const;
			void									ShowAllOptions()											const;
			void									ShowWelcomeMessage()										const;
			void									SetActiveStatus(bool active)											{ isActive = active; }
	virtual	void									ValidateKeyPressed(std::string key)							const;

protected:
	void											SetWelcomeMessage(std::string message)									{ welcomeMessage = message; }
	std::string	welcomeMessage;
	std::map<std::string, std::string> optionKeys;
	Game& game;
	bool isActive;
private:
};

