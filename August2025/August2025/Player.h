#pragma once

#include <SFML/Graphics.hpp>
#include "Globals.h"

class Player
{
public:
	Player();

	bool Move(Direction t_direction);
	bool Move(sf::Vector2f t_direction);


	void Update(sf::Time t_deltaTime);
	void render(sf::RenderWindow& t_renderWindow);

private:
	sf::Texture m_playerTexture;
	sf::Sprite m_playerSprite;
	sf::Vector2f m_position;
	sf::Vector2f m_velocity;
	sf::Vector2f m_acceleration;

	float m_gravity = 9.8f;
	float m_friction = 0.9f;
	float m_moveSpeed;

	bool landed = false;
};

