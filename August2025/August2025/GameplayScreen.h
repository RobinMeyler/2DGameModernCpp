#pragma once


#include <SFML/Graphics.hpp>
#include "Player.h"


class GameplayScreen
{
public:
	GameplayScreen();

	void update(sf::Time t_deltaTime);
	void render(sf::RenderWindow& t_renderWindow);

private:
	sf::RectangleShape Ground;
	Player m_Player;
	float m_movementSpeed;
};

