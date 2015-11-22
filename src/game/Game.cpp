#include "Game.hpp"

#include "GameState.hpp"

#include <SFML/Window.hpp>

#include <thread>
#include <chrono>
#include <memory>

using namespace falksalt;


Game::Game(int*, char**)
	: m_logger(om::Logger::get("Game"))
{
	m_logger << "Initialized." << std::endl;

	m_stateStack.push(std::make_shared<GameState>());
}

Game::~Game()
{
}

void Game::start()
{
	m_logger << "Starting game loop." << std::endl;
	m_stop = false;
	
	m_lastTick = std::chrono::system_clock::now();

	while(!m_stop)
	{
		sf::Event event;
		while(m_renderer.getWindow().pollEvent(event))
		{
			if(event.type == sf::Event::Closed)
				stop();
			//else if(event.type == sf::Event::Resized)
			//	m_renderer.resize(event.size.width, event.size.height);
		}
		
		// TODO: Perhaps use double instead of float? Seems a bit flakey
		// at high frame rates.
		m_stateStack.update(getAndUpdateDelta());

		m_renderer.beginRender();
		m_stateStack.render(m_renderer);
		m_renderer.finishRender();

		std::this_thread::sleep_for(std::chrono::milliseconds(1));
	}
	m_logger << "Game loop stopped." << std::endl;
}

void Game::stop()
{
	m_stop = true;
}

void Game::update()
{
}

// Updates the m_lastTick field and returns the time delta in seconds.
float Game::getAndUpdateDelta()
{
	auto now = std::chrono::system_clock::now();
	auto delta = std::chrono::duration_cast<std::chrono::milliseconds>
		(now - m_lastTick);

	m_lastTick = now;
	return delta.count() / 1000.f;
}

