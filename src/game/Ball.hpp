#pragma once

#include "Block.hpp"

#include <glm/glm.hpp>

namespace falksalt
{
	class Ball final
	{
	public:
		static const constexpr float Diameter = Block::Height / 2.f;
		static const constexpr float InitialVelocityX = 0.0f;
		static const constexpr float InitialVelocityY = 1.0f;
		static const constexpr float BaseSpeed = 1.0f; // One unit a second

		Ball(float x, float y);

		void update(float delta);

		glm::vec2 getPosition() const;

	private:
		float getSpeed() const;

		glm::vec2 m_position, m_velocity;
	};
}

