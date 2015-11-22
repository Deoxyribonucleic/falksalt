#pragma once

#include "Block.hpp"


namespace falksalt
{
	class Pad final
	{
	public:
		Pad();

		static const constexpr float VerticalPosition = 3/4.f - Block::Height; 
		static const constexpr float Width = Block::Width * 2.f; 
		static const constexpr float Height = Block::Height / 2.f;
		
		float getPosition() const;
		void setVelocity(float vel);

		void update(float delta);
		
	private:
		float m_position;
		float m_velocity;
	};
}

