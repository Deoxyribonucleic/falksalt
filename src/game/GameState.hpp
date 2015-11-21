#pragma once

#include "State.hpp"

#include "om/util/log/Logger.hpp"


namespace falksalt
{
	class GameState final : public State
	{
	public:
		GameState();

		void update();

	private:
		om::Logger& m_logger;
	};
}

