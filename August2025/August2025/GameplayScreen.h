#pragma once


#include <SFML/Graphics.hpp>

class GameplayScreen
{
public:
	GameplayScreen();

	void update(sf::Time t_deltaTime);
	void render(sf::RenderWindow& t_renderWindow);

private:
	sf::RectangleShape Ground;
	sf::RectangleShape Player;
	float m_movementSpeed;
};

