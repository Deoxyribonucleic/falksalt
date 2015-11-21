#pragma once

#include "Uncopiable.hpp"

namespace falksalt
{
	class State : Uncopiable
	{
	public:
		virtual ~State() {};

		virtual void update() = 0;
	};
}

