#pragma once

#include "Uncopiable.hpp"

namespace falksalt
{
	class Renderer;
	class SoundManager;
	class State : Uncopiable
	{
	public:
		virtual ~State() {};

		virtual void update(float delta, bool top) = 0;
		virtual void render(Renderer& renderer) = 0;
	};
}

