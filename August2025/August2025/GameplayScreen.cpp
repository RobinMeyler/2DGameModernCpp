#include "GameplayScreen.h"
#include "ScreenManager.h"

GameplayScreen::GameplayScreen() :
	m_movementSpeed(10.0f)
{
	Ground.setFillColor(sf::Color::Red);
	Ground.setPosition(sf::Vector2f(0, ScreenManager::getInstance().getHeight<float>() - ScreenManager::getInstance().getHeight<float>() / 3));
	Ground.setSize(sf::Vector2f((ScreenManager::getInstance().getWidth<float>()), ScreenManager::getInstance().getHeight<float>() / 2));

	Player.setFillColor(sf::Color::Blue);
	Player.setPosition(sf::Vector2f(100, 100));
	Player.setSize(sf::Vector2f(200,200));
}

void GameplayScreen::update(sf::Time t_deltaTime)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::D))
	{
		Player.setPosition(sf::Vector2f(Player.getPosition().x + 5, Player.getPosition().y));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::W))
	{
		Player.setPosition(sf::Vector2f(Player.getPosition().x, Player.getPosition().y - 5));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::A))
	{
		Player.setPosition(sf::Vector2f(Player.getPosition().x - 5, Player.getPosition().y));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::S))
	{
		Player.setPosition(sf::Vector2f(Player.getPosition().x, Player.getPosition().y +5));
	}
}

void GameplayScreen::render(sf::RenderWindow& t_renderWindow)
{
	t_renderWindow.draw(Ground);
	t_renderWindow.draw(Player);
}
