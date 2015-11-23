#include "GameState.hpp"

#include "audio/SoundManager.hpp"
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
}

void GameState::update(float delta, SoundManager& soundMgr, bool)
{
	m_padController.update();

	m_pad.setVelocity(m_padController.getInputVelocity());
	m_pad.update(delta);

	m_ball.update(delta, m_pad, m_blocks, soundMgr);
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

