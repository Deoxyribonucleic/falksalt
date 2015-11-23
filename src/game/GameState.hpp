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
	class GameState final : public State
	{
	public:
		GameState();

		void update(float delta, SoundManager& soundMgr, bool top);
		void render(Renderer& renderer);

	private:
		om::Logger& m_logger;

		Ball m_ball;
		Pad m_pad;
		PadController m_padController;
		std::array<std::array<Block, Block::LayerWidth>, Block::Layers> m_blocks;
	};
}

