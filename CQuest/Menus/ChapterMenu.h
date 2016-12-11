#pragma once

#include "Menus\Menu.h"
#include "Setting\Chapter.h"

class Game;
class Chapter;

class ChapterMenu : public Menu
{
public:
	ChapterMenu(Game& gameReference, Chapter newChapter);
	~ChapterMenu();

				void		AddStoryOptions();
				void		ChangeChapter(Chapter newChapter);
	virtual		void		Initialize()										override;
	virtual		void		ProcessOptionKeyPress(std::string key)				override;
	virtual		void		ValidateKeyPressed(std::string key)					override;

private:
	Chapter chapter;
};