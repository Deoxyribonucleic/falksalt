#pragma once

#include "State.hpp"

#include "Ball.hpp"
#include "Block.hpp"
#include "Pad.hpp"
#include "PadController.hpp"

#include "om/util/log/Logger.hpp"

#include <array>


namespace falksalt
{
	class Renderer;
	class SoundManager;
	class Game;
	class GameState final : public State
	{
	public:
		typedef std::array<std::array<Block, Block::LayerWidth>,
				Block::Layers> BlockList;

		GameState(Game& game);

		void update(float delta, bool top);
		void render(Renderer& renderer);

		void destroyBlock(Block const& block);
		BlockList const& getBlocks() const;

		int getScore() const;

	private:
		om::Logger& m_logger;

		Game& m_game;

		Ball m_ball;
		Pad m_pad;
		PadController m_padController;
		int m_score;

		BlockList m_blocks;
	};
}

