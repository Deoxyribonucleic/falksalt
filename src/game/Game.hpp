#pragma once

#include "Uncopiable.hpp"
#include "StateStack.hpp"
#include "graphics/Renderer.hpp"

#include <om/util/log/Logger.hpp>

#include <memory>


namespace falksalt
{
	class Game final : Uncopiable
	{
	public:
		Game(int* argc, char** argv);
		~Game();

		void start();
		void stop();

	private:
		om::Logger& m_logger;
		Renderer m_renderer;
		StateStack m_stateStack;
		
		bool m_stop;

		void update();
	};
}

