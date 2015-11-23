#include "Ball.hpp"

#include "Board.hpp"
#include "Pad.hpp"

#include <iostream>

#include <glm/gtc/constants.hpp>

using namespace falksalt;

Ball::Ball(float x, float y)
	: m_position(x, y), m_velocity(1.0f, 1.0f), frame(0)
{
}

void Ball::update(float delta, Pad const& pad,
		std::array<std::array<Block, Block::LayerWidth>, Block::Layers>&
		blocks)
{
	m_velocity = glm::normalize(m_velocity) * getSpeed();

	move(delta, pad, blocks);
	++frame;

	// Bounce against walls
	if(m_position.x < -1 || m_position.x > 1)
		m_velocity.x *= -1;
	if(m_position.y < -Board::Height || m_position.y > Board::Height)
		m_velocity.y *= -1;
}

void Ball::move(float delta, Pad const& pad,
		std::array<std::array<Block, Block::LayerWidth>, Block::Layers>& blocks)
{
	//if(delta < 0.02f)
	//	std::cout << delta << std::endl;
	glm::vec2 movement = m_velocity * delta;
	
	Collision collision;
	if((collision = collide(movement, pad, blocks)).collision)
	{
		std::cout << "collision" << frame << std::endl;
		float remainingDelta = delta -
			delta * (glm::length(collision.where - m_position)
					/ glm::length(movement));

		if(collision.object) // If we've collided with a block, reverse appropriate
			// direction...
		{
			if(collision.side == Side::Up || collision.side == Side::Down)
				m_velocity.y *= -1;
			else
				m_velocity.x *= -1;
		}
		else
		{
			// TODO: move these calculations to Pad
			float angle = glm::pi<float>() / 2 +
					glm::pi<float>() / 3 *
					((pad.getPosition() - collision.where.x) / (Pad::Width / 2));

			m_velocity.x = glm::cos(angle);
			m_velocity.y = -glm::sin(angle);
		}

		m_position = collision.where;

		move(remainingDelta, pad, blocks);
	}
	else
	{
		m_position += movement;
	}
}

Collision Ball::collide(glm::vec2 const& movement,
		Pad const& pad,
		std::array<std::array<Block, Block::LayerWidth>, Block::Layers>&
			blocks)
{
	std::vector<Collision> collisions;
	
	collisions.push_back(pad.collides(m_position, m_position + movement));
	for(size_t l = 0; l<blocks.size(); ++l)
	{
		for(size_t b = 0; b<blocks[l].size(); ++b)
		{
			collisions.push_back(blocks[l][b].collides(m_position,
						m_position + movement));
		}
	}

	auto collision = closest(m_position, collisions);
	if(collision.collision && collision.object) // If we've collided with a brick
	{
		((Block*)collision.object)->destroy();
	}

	return collision;
}

glm::vec2 Ball::getPosition() const
{
	return m_position;
}

float Ball::getSpeed() const
{
	return BaseSpeed;
}

