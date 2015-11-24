#pragma once

#include "State.hpp"

#include <memory>
#include <stack>

namespace falksalt
{
	class Renderer;
	class SoundManager;
	class StateStack final
	{
	public:
		void push(std::shared_ptr<State> state);
		void pop();

		void update(float delta);
		void render(Renderer& renderer);

	private:
		std::stack<std::shared_ptr<State>> m_stack;
		
	};
}

