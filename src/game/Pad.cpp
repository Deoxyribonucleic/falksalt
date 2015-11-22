#include "Pad.hpp"

using namespace falksalt;

Pad::Pad()
	: m_position(0.0f), m_velocity(0.f)
{
}

float Pad::getPosition() const
{
	return m_position;
}

void Pad::setVelocity(float vel)
{
	m_velocity = vel;
}

void Pad::update(float delta)
{
	m_position += m_velocity * Speed * delta;
	
	if(m_position > 1.0)
		m_position = 1.0;
	else if(m_position < -1.0)
		m_position = -1.0;
}

Collision Pad::collides(glm::vec2 start, glm::vec2 end) const
{
	auto collision = intersects(start, end,
				glm::vec2(
					m_position - Pad::Width / 2.f, 0+Pad::VerticalPosition),
				glm::vec2(
					m_position + Pad::Width / 2.f, 0+Pad::VerticalPosition)
				);
	collision.side = Side::Up;
	collision.object = nullptr;
	return collision;
}

