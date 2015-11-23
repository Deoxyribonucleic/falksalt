#pragma once

#include "Block.hpp"

#include <glm/glm.hpp>

namespace falksalt
{
	class Pad;
	class SoundManager;
	class Ball final
	{
	public:
		static const constexpr float Diameter = Block::Height / 2.f;
		static const constexpr float InitialVelocityX = 0.0f;
		static const constexpr float InitialVelocityY = 1.0f;
		static const constexpr float BaseSpeed = 0.75f; // One unit a second

		Ball(float x, float y);

		void update(float delta, Pad const& pad,
				std::array<std::array<Block, Block::LayerWidth>,
					Block::Layers>& blocks,
					SoundManager& soundMgr);

		glm::vec2 getPosition() const;

	private:
		float getSpeed() const;

		void move(float delta, Pad const& pad,
			std::array<std::array<Block, Block::LayerWidth>,
			Block::Layers>& blocks,
			SoundManager& soundMgr);

		Collision collide(glm::vec2 const& movement,
				Pad const& pad,
				std::array<std::array<Block, Block::LayerWidth>, Block::Layers>&
					blocks,
				SoundManager& soundMgr);

		glm::vec2 m_position, m_velocity;
		int frame;
	};
}

