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
	while(!m_stop)
	{
		//sf::Event event;
		//while(m_renderer.get_window().pollEvent(event))
		//{
		//	if(event.type == sf::Event::Closed)
		//		stop();
		//	else if(event.type == sf::Event::Resized)
		//		m_renderer.resize(event.size.width, event.size.height);
		//}

		m_stateStack.update();

		//m_renderer.render(m_pyramid);
		//m_renderer.render(m_camera, m_shader);

		//std::this_thread::sleep_for(std::chrono::milliseconds(1));
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

