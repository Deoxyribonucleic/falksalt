#include "PadController.hpp"

#include <SFML/Window.hpp>

using namespace falksalt;

PadController::PadController()
	: m_inputVelocity(0.f)
{
}

float PadController::getInputVelocity()
{
	return m_inputVelocity;
}

void PadController::update()
{
	m_inputVelocity = 0.f;

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		m_inputVelocity++;
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		m_inputVelocity--;
}

