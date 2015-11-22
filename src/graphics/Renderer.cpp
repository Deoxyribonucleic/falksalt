#include "Renderer.hpp"

#include "game/Ball.hpp"
#include "game/Block.hpp"
#include "game/Pad.hpp"

#include <cassert>

using namespace falksalt;

Renderer::Renderer()
	: m_window(sf::VideoMode(1280, 960), "Project Falksalt", sf::Style::Default)
{
}

Renderer::~Renderer()
{
}

sf::Window& Renderer::getWindow()
{
	return m_window;
}

void Renderer::beginRender()
{
	m_window.clear(sf::Color(0, 0, 0, 255));
}

void Renderer::finishRender()
{
	m_window.display();
}

void Renderer::render(Pad const& pad)
{
	sf::RectangleShape rect(sf::Vector2f(
				unitsToPixelsX(Pad::Width), unitsToPixelsY(Pad::Height)));

	rect.setPosition(sf::Vector2f(
				worldToScreenX(pad.getPosition()) - rect.getSize().x/2.0f,
				worldToScreenY(Pad::VerticalPosition)));
	m_window.draw(rect);
}

void Renderer::render(Block const& block)
{
	sf::RectangleShape rect(sf::Vector2f(
				unitsToPixelsX(Block::Width),
				unitsToPixelsY(Block::Height)));

	rect.setFillColor(getBlockColor(block.getLayer()));

	rect.setPosition(sf::Vector2f(
				worldToScreenX(block.getX()),
				worldToScreenY(block.getY())));
	m_window.draw(rect);
}

void Renderer::render(Ball const& ball)
{
	sf::RectangleShape rect(sf::Vector2f(
				unitsToPixelsX(Ball::Diameter),
				unitsToPixelsY(Ball::Diameter)));

	rect.setPosition(worldToScreen(ball.getPosition())
			- sf::Vector2f(
				unitsToPixelsX(Ball::Diameter) / 2.f,
				unitsToPixelsY(Ball::Diameter) / 2.f));

	m_window.draw(rect);
}

float Renderer::worldToScreenX(float x) const
{
	return m_window.getSize().x/2 + unitsToPixelsX(x);
}

float Renderer::worldToScreenY(float y) const
{
	return m_window.getSize().y/2 + unitsToPixelsY(y);
}

sf::Vector2f Renderer::worldToScreen(glm::vec2 const& vec) const
{
	return sf::Vector2f(
			worldToScreenX(vec.x),
			worldToScreenY(vec.y));
}

float Renderer::unitsToPixelsX(float x) const
{
	return x * (m_window.getSize().x / 2.0f);
}

float Renderer::unitsToPixelsY(float y) const
{
	return y * (m_window.getSize().y/2.f * (1.f / 0.75f));
}

sf::Color Renderer::getBlockColor(int layer) const
{
	assert(layer < 8);
	static sf::Color rainbow[] = {
		sf::Color(255, 0, 0, 255), // Red
		sf::Color(255, 128, 0, 255), // Orange
		sf::Color(255, 255, 0, 255), // Yellow
		sf::Color(0, 255, 0, 255), // Green
		sf::Color(0, 255, 255, 255), // Teal
		sf::Color(0, 0, 255, 255), // Blue
		sf::Color(128, 0, 255, 255), // Purple
		sf::Color(255, 0, 255, 255) // Magenta
	};
	return rainbow[layer];
}

