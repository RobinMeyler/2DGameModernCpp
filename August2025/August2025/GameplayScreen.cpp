#include "GameplayScreen.h"
#include "ScreenManager.h"
#include "Globals.h"


GameplayScreen::GameplayScreen() :
	m_movementSpeed(10.0f)
{
	Ground.setFillColor(sf::Color::Red);
	Ground.setPosition(sf::Vector2f(0, ScreenManager::getInstance().getHeight<float>() - ScreenManager::getInstance().getHeight<float>() / 3));
	Ground.setSize(sf::Vector2f((ScreenManager::getInstance().getWidth<float>()), ScreenManager::getInstance().getHeight<float>() / 2));

}

void GameplayScreen::update(sf::Time t_deltaTime)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::D))
	{
		m_Player.Move(Direction::Right);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::W))
	{
		m_Player.Move(Direction::Up);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::A))
	{
		m_Player.Move(Direction::Left);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::S))
	{
		m_Player.Move(Direction::Down);
	}
	m_Player.Update(t_deltaTime);
}

void GameplayScreen::render(sf::RenderWindow& t_renderWindow)
{
	t_renderWindow.draw(Ground);
	m_Player.render(t_renderWindow);
}
