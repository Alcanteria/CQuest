#pragma once

#include <string>

class Game;

class Logo
{
public:
	Logo(Game& gameReference);
	~Logo();

	const static std::string LOGO_FILE_NAME;

	const	void	ShowLogo()	const;
			Game&	GetGame()	const	{ return game; }

private:
	Game& game;
};

