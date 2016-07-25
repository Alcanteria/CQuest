#pragma once

#include <string>
#include <map>
#include <vector>

class Game;

class Menu
{

public:
	Menu(Game* game);
	~Menu();

	// List of possible menus.
	enum MENUS { MAIN, CHARACTER_SELECT, GAME_OVER, NONE };

	// Default exit menu value.
	const std::string EXIT = "*****EXIT*****";

	// Default "back to previous menu" value.
	const std::string GO_BACK = "<----GO BACK";

	const	std::string								GetWelcomeMessage()											const		{ return welcomeMessage; }
	const	bool									IsActive()													const		{ return isActive; }
	const	void									SetActiveStatus(bool active)											{ isActive = active; }
			void									ShowWelcomeMessage()										const;
	const	bool									IsOptionKeyPresent(std::string key)							const;
			void									AddOptionKey(std::string key, std::string description);
	const	std::map<std::string, std::string>		GetOptionKeys()												const		{ return optionKeys; }
			void									ShowAllOptions()											const;
	virtual	void									ValidateKeyPressed(std::string key)							const;
	virtual	void									ProcessOptionKeyPress(std::string key)						const;
	const	static	void							PrintGap(int spaces = 3);
	const	void									PrintInvalidOption()										const;
protected:
	void											SetWelcomeMessage(std::string message)									{ welcomeMessage = message; }
	std::string	welcomeMessage;
	std::map<std::string, std::string> optionKeys;
	Game* game;
	bool isActive;
private:
};

