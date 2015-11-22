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
	m_position += m_velocity * delta;
	
	if(m_position > 1.0)
		m_position = 1.0;
	else if(m_position < -1.0)
		m_position = -1.0;
}

