#include "Game.h"
#include <iostream>
#include "ScreenManager.h"

// Initalizer List is/Is not in order - Look up this fact again
Game::Game()
	: m_currentGameMode(GameMode::Gameplay),
	  m_renderWindow{ sf::VideoMode({ ScreenManager::getInstance().getWidth<unsigned int>(), ScreenManager::getInstance().getHeight<unsigned int>()}), 
	"August", sf::Style::Titlebar | sf::Style::Resize | sf::Style::Close, sf::State::Windowed }
{
}

void Game::run()
{
	sf::Clock gameClock;											// Game clock
	sf::Time timeTakenForUpdate = sf::Time::Zero;					// No lag on first input
	sf::Time timePerFrame = sf::seconds(1.f / 60.f);				// 60 frames per second
	while (m_renderWindow.isOpen())									// Loop
	{
		processInput();												// Check for input
		timeTakenForUpdate += gameClock.restart();					// Returns time take to do the loop
		while (timeTakenForUpdate > timePerFrame)					// Update enough times to catch up on updates missed during the lag time
		{
			timeTakenForUpdate -= timePerFrame;						// Decrement lag
			processInput();											// More checks, the more accurate input to display will be
			update(timePerFrame);									// Update
		}
		render();
	}
}

void Game::intialize()
{
}

void Game::processInput()
{
	while (const std::optional event = m_renderWindow.pollEvent())
	{
		// "close requested" event: we close the window
		if (event->is<sf::Event::Closed>())
		{
			m_renderWindow.close();
		}
		else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>())
		{
			if (keyPressed->scancode == sf::Keyboard::Scancode::Escape)
			{
				m_renderWindow.close();
			}
		}


		if (const auto* MousePressed = event->getIf<sf::Event::MouseButtonPressed>())
		{
			if (MousePressed->button == sf::Mouse::Button::Right)
			{
				std::cout << "the right button was pressed" << std::endl;
				std::cout << "mouse x: " << MousePressed->position.x << std::endl;
				std::cout << "mouse y: " << MousePressed->position.y << std::endl;
			}
		}
		if (const auto* MouseReleased = event->getIf<sf::Event::MouseButtonReleased>())
		{
			if (MouseReleased->button == sf::Mouse::Button::Right)
			{
				std::cout << "the right button was pressed" << std::endl;
				std::cout << "mouse x: " << MouseReleased->position.x << std::endl;
				std::cout << "mouse y: " << MouseReleased->position.y << std::endl;
			}
		}
		if (const auto* mouseWheelScrolled = event->getIf<sf::Event::MouseWheelScrolled>())
		{
			// display number of ticks mouse wheel has moved
			switch (mouseWheelScrolled->wheel)
			{
			case sf::Mouse::Wheel::Vertical:
				std::cout << "wheel type: vertical" << std::endl;
				break;
			case sf::Mouse::Wheel::Horizontal:
				std::cout << "wheel type: horizontal" << std::endl;
				break;
			}
		}
		if (const auto* mouseMoved = event->getIf<sf::Event::MouseMoved>())
		{
			std::cout << "new mouse x: " << mouseMoved->position.x << std::endl;
			std::cout << "new mouse y: " << mouseMoved->position.y << std::endl;
		}
		if (const auto* mouseMovedRaw = event->getIf<sf::Event::MouseMovedRaw>())
		{
			std::cout << "new mouse Raw x: " << mouseMovedRaw->delta.x << std::endl;
			std::cout << "new mouse Raw y: " << mouseMovedRaw->delta.y << std::endl;
		}
	}
}


void Game::update(sf::Time t_deltaTime)
{
	switch (m_currentGameMode)					// Switch to control the screens
	{
	case GameMode::MainMenu:
		
		break;
	case GameMode::Gameplay:
		m_gameplayScreen.update(t_deltaTime);
		break;
	default:
		break;
	}

}

void Game::render()
{
	// clear the window with black color
	m_renderWindow.clear(sf::Color::Blue);

	switch (m_currentGameMode)					
	{
	case GameMode::MainMenu:

		break;
	case GameMode::Gameplay:
		m_gameplayScreen.render(m_renderWindow);
		break;
	default:
		break;
	}

	m_renderWindow.display();

}
