#pragma once

#include "State.hpp"

#include "Pad.hpp"
#include "PadController.hpp"

#include "om/util/log/Logger.hpp"


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
	};
}

