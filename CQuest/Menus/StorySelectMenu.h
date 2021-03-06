#pragma once
#include "Menus\Menu.h"
#include <vector>

class Game;

class StorySelectMenu : public Menu
{
public:
	StorySelectMenu(Game& gameReference);
	~StorySelectMenu();

				void		AddStoryOptions();
	virtual		void		Initialize()										override;
	virtual		void		ProcessOptionKeyPress(std::string key)				override;
	virtual		void		ValidateKeyPressed(std::string key)					override;

private:

	// Store the ID codes for each possible story.
	std::vector<std::string> storyIDs;
};

