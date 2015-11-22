#include "Ball.hpp"

#include "Board.hpp"

using namespace falksalt;

Ball::Ball(float x, float y)
	: m_position(x, y), m_velocity(1.0f, 1.0f)
{
}

void Ball::update(float delta)
{
	m_velocity = glm::normalize(m_velocity) * getSpeed();
	m_position += m_velocity * delta;

	// Bounce against walls
	if(m_position.x < -1 || m_position.x > 1)
		m_velocity.x *= -1;
	if(m_position.y < -Board::Height || m_position.y > Board::Height)
		m_velocity.y *= -1;
}

glm::vec2 Ball::getPosition() const
{
	return m_position;
}

float Ball::getSpeed() const
{
	return BaseSpeed;
}

