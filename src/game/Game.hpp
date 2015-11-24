#pragma once

#include "Uncopiable.hpp"
#include "StateStack.hpp"
#include "graphics/Renderer.hpp"
#include "audio/SoundManager.hpp"

#include <om/util/log/Logger.hpp>

#include <memory>
#include <chrono>


namespace falksalt
{
	class Game final : Uncopiable
	{
	public:
		Game(int* argc, char** argv);
		~Game();

		void start();
		void stop();
		
		SoundManager& getSoundManager();

	private:
		om::Logger& m_logger;
		Renderer m_renderer;
		StateStack m_stateStack;
		SoundManager m_soundManager;

		std::chrono::system_clock::time_point m_lastTick;
		
		bool m_stop;

		void update();

		float getAndUpdateDelta();
	};
}

