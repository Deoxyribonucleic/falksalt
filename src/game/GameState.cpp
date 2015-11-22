#include "GameState.hpp"

#include "graphics/Renderer.hpp"
#include "Collision.hpp"

#include <SFML/Graphics.hpp>

using namespace falksalt;

GameState::GameState()
	: m_logger(om::Logger::get("GameState")),
	  m_ball(0, 0)
{
	for(int l = 0; l < Block::Layers; ++l)
	{
		for(int b = 0; b < Block::LayerWidth; ++b)
		{
			m_blocks[l][b] = Block(l, b * Block::Width - 1.0f);
		}
	}

	glm::vec2 where(2, 2);
	bool intersect = intersects(glm::vec2(-1, -1), glm::vec2(1, 1),
			glm::vec2(1, -1), glm::vec2(0, 1), where);
	std::cout << where.x << "," << where.y << ": " << intersect << std::endl;
}

void GameState::update(float delta, bool)
{
	m_padController.update();

	m_pad.setVelocity(m_padController.getInputVelocity());
	m_pad.update(delta);

	m_ball.update(delta, m_pad);
}

void GameState::render(Renderer& renderer)
{
	renderer.render(m_pad);
	for(int l = 0; l < Block::Layers; ++l)
	{
		for(int b = 0; b < Block::LayerWidth; ++b)
		{
			renderer.render(m_blocks[l][b]);
		}
	}
	renderer.render(m_ball);
}

