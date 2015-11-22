#pragma once

#include "Block.hpp"
#include "Collision.hpp"

#include <glm/glm.hpp>


namespace falksalt
{
	class Pad final
	{
	public:
		Pad();

		static const constexpr float VerticalPosition = 3/4.f - Block::Height; 
		static const constexpr float Width = Block::Width * 2.f; 
		static const constexpr float Height = Block::Height / 2.f;
		static const constexpr float Speed = 2.0f;
		
		float getPosition() const;
		void setVelocity(float vel);

		void update(float delta);

		Collision collides(glm::vec2 start, glm::vec2 end) const;
		
	private:
		float m_position;
		float m_velocity;
	};
}

