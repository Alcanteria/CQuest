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

	const	std::string						GetWelcomeMessage()									const		{ return welcomeMessage; }
	const	bool							IsActive()											const		{ return isActive; }
	const	void							SetActiveStatus(bool active)									{ isActive = active; }
			void							ShowWelcomeMessage()								const;
	const	bool							IsOptionKeyPresent(char key)						const;
			void							AddOptionKey(char key, std::string description);
	const	std::map<char, std::string>		GetOptionKeys()										const		{ return optionKeys; }
			void							ShowAllOptions()									const;
	virtual	void							CheckKeyPressed(char key)							const;
	virtual	void							ProcessOptionKeyPress(char key)						const;
protected:
	void									SetWelcomeMessage(std::string message)							{ welcomeMessage = message; }
	std::string	welcomeMessage;
	std::map<char, std::string> optionKeys;
	Game* game;
	bool isActive;
private:
};

