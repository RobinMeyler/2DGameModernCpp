#include "Player.h"

Player::Player() :
    m_moveSpeed{10},
	m_playerTexture("Player.png"),
	m_playerSprite(m_playerTexture)
{
}

bool Player::Move(Direction t_direction)
{
	// Add Velocity
	switch (t_direction)	
	{
	case Direction::Left:
		m_acceleration = {-m_moveSpeed ,0 };
		break;
	case Direction::Right:
		m_acceleration = { m_moveSpeed ,0 };
		break;
	case Direction::Up:
		m_acceleration = { 0, -m_moveSpeed };
		break;
	case Direction::Down:
		m_acceleration = { 0, m_moveSpeed };
		break;
	default:
		break;
	}
	return true;
}

bool Player::Move(sf::Vector2f t_direction)
{
    return false;
}

void Player::Update(sf::Time t_deltaTime)
{
	// if(collides with ground)
	m_velocity = m_velocity * m_friction;
	//m_velocity = m_velocity * m_gravity;

	m_velocity = m_velocity + m_acceleration;
	m_position = m_position + m_velocity;



	m_playerSprite.setPosition(m_position);
	m_acceleration = { 0, 0 };
}

void Player::render(sf::RenderWindow& t_renderWin)
{
    t_renderWin.draw(m_playerSprite);
}