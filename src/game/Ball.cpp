#include "Ball.hpp"

#include "Board.hpp"
#include "Pad.hpp"

#include <iostream>

using namespace falksalt;

Ball::Ball(float x, float y)
	: m_position(x, y), m_velocity(1.0f, 1.0f)
{
}

void Ball::update(float delta, Pad const& pad)
{
	m_velocity = glm::normalize(m_velocity) * getSpeed();

	move(delta, pad);

	// Bounce against walls
	if(m_position.x < -1 || m_position.x > 1)
		m_velocity.x *= -1;
	if(m_position.y < -Board::Height || m_position.y > Board::Height)
		m_velocity.y *= -1;
}

void Ball::move(float delta, Pad const& pad)
{
	//if(delta < 0.02f)
	//	std::cout << delta << std::endl;
	glm::vec2 movement = m_velocity * delta;
	
	glm::vec2 where;
	if(pad.collides(m_position, m_position + movement, where) != Collision::None)
	{
		std::cout << "collision" << std::endl;
		float remainingDelta = delta -
			delta * (glm::length(where - m_position) / glm::length(movement));

		m_velocity.y *= -1;
		m_position = where;

		move(remainingDelta, pad);
	}
	else
	{
		m_position += movement;
	}
}

glm::vec2 Ball::getPosition() const
{
	return m_position;
}

float Ball::getSpeed() const
{
	return BaseSpeed;
}

