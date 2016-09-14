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
	enum MENUS { MAIN, CHARACTER_SELECT, GAME_OVER, NONE };

	// Default exit menu value.
	const std::string EXIT = "*****EXIT*****";

	// Default "back to previous menu" value.
	const std::string GO_BACK = "<----GO BACK";

	const	void									AddOptionKey(std::string key, std::string description);
			Game&									GetGame()													const		{ return game; }
	const	std::map<std::string, std::string>		GetOptionKeys()												const		{ return optionKeys; }
	const	std::string								GetWelcomeMessage()											const		{ return welcomeMessage; }
	const	bool									IsActive()													const		{ return isActive; }
	const	bool									IsOptionKeyPresent(std::string key)							const;
	const	static	void							PrintChunk();
	const	static	void							PrintGap(int spaces = 3);
	const	void									PrintInvalidOption()										const;
	const	static	void							PrintSeperator();
	virtual	void									ProcessOptionKeyPress(std::string key)						const;
	const	void									ShowAllOptions()											const;
	const	void									ShowWelcomeMessage()										const;
	const	void									SetActiveStatus(bool active)											{ isActive = active; }
	virtual	void									ValidateKeyPressed(std::string key)							const;

protected:
	void											SetWelcomeMessage(std::string message)									{ welcomeMessage = message; }
	std::string	welcomeMessage;
	std::map<std::string, std::string> optionKeys;
	Game& game;
	bool isActive;
private:
};

