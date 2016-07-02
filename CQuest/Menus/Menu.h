#pragma once

#include <string>

class Menu
{
public:
	Menu();
	~Menu();

	const std::string GetWelcomeMessage() const { return welcomeMessage; }
	const bool IsActive() const { return isActive; }
	void SetActiveStatus(bool active) { isActive = active; }
	void ShowWelcomeMessage() const;
protected:
	void SetWelcomeMessage(std::string message){ welcomeMessage = message; }
	std::string welcomeMessage;
private:
	bool isActive;

};

