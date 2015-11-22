#pragma once

#include "State.hpp"

#include "Pad.hpp"
#include "PadController.hpp"
#include "Block.hpp"

#include "om/util/log/Logger.hpp"

#include <array>


namespace falksalt
{
	class Renderer;
	class GameState final : public State
	{
	public:
		GameState();

		void update(float delta, bool top);
		void render(Renderer& renderer);

	private:
		om::Logger& m_logger;

		Pad m_pad;
		PadController m_padController;
		std::array<std::array<Block, Block::LayerWidth>, Block::Layers> m_blocks;
	};
}

