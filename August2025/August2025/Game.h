#pragma once

#include <SFML/Graphics.hpp>

#include "Globals.h"

#include "GameplayScreen.h"

class Game
{
public:

	Game();

	void run();
	void intialize();
	void update(sf::Time t_deltaTime);
	void processInput();
	void render();




private:

	sf::RenderWindow m_renderWindow;
	GameMode m_currentGameMode;
	GameplayScreen m_gameplayScreen;
};

