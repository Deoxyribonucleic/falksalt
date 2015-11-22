#include "GameState.hpp"

#include "graphics/Renderer.hpp"

#include <SFML/Graphics.hpp>

using namespace falksalt;

GameState::GameState()
	: m_logger(om::Logger::get("GameState"))
{
}

void GameState::update(float delta, bool)
{
	m_padController.update();

	m_logger.debug() << delta << ", " << m_padController.getInputVelocity() << std::endl;

	m_pad.setVelocity(m_padController.getInputVelocity());
	m_pad.update(delta);
}

void GameState::render(Renderer& renderer)
{
	renderer.render(m_pad);
}

