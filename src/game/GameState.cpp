#include "GameState.hpp"

#include "Collision.hpp"
#include "Game.hpp"
#include "audio/SoundManager.hpp"
#include "graphics/Renderer.hpp"

#include <SFML/Graphics.hpp>

using namespace falksalt;

GameState::GameState(Game& game)
	: m_logger(om::Logger::get("GameState")),
	  m_game(game),
	  m_ball(*this, 0, 0),
	  m_score(0)
{
	for(int l = 0; l < Block::Layers; ++l)
	{
		for(int b = 0; b < Block::LayerWidth; ++b)
		{
			m_blocks[l][b] = Block(l, b);
		}
	}
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

bool layerIsCleared(
		GameState::BlockList const& blocks,
		int layer)
{
	assert(layer > -1 && (unsigned int)layer < blocks.size());
	
	for(size_t i=0; i<blocks[layer].size(); ++i)
	{
		if(!blocks[layer][i].isDestroyed())
			return false;
	}
	return true;
}

void GameState::destroyBlock(Block const& block)
{
	m_score += m_blocks[block.getLayer()][block.getIndex()].destroy();
	m_logger.info() << "Score: " << m_score << std::endl;

	if(layerIsCleared(m_blocks, block.getLayer()))
		m_game.getSoundManager().playSpecialChime();
	else
		m_game.getSoundManager().playChime();
}

GameState::BlockList const& GameState::getBlocks() const
{
	return m_blocks;
}

int GameState::getScore() const
{
	return m_score;
}

