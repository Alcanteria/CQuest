#pragma once

#include <string>

class MainMenu
{
public:
	MainMenu();
	~MainMenu();

	std::string GetWelcomeMessage() const { return welcomeMessage; }
	void SetActiveStatus(bool status);
	bool IsActive() const;
private:
	std::string welcomeMessage;
	bool isActive;
};

