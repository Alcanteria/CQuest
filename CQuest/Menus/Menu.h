#pragma once

#include <string>
#include <map>
#include <vector>

class Menu
{
public:
	Menu();
	~Menu();

	const std::string GetWelcomeMessage() const { return welcomeMessage; }
	const bool IsActive() const { return isActive; }
	void SetActiveStatus(bool active) { isActive = active; }
	void ShowWelcomeMessage() const;
	const bool IsOptionKeyPresent(char key) const;
	void AddOptionKey(char key);
protected:
	void SetWelcomeMessage(std::string message){ welcomeMessage = message; }
	std::string welcomeMessage;
	std::vector<char> optionKeys;
private:
	bool isActive;
};

