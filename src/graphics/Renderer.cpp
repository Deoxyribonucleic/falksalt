#include "Renderer.hpp"

#include "game/Pad.hpp"

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

float Renderer::worldToScreenX(float x) const
{
	return m_window.getSize().x/2 + unitsToPixelsX(x);
}

float Renderer::worldToScreenY(float y) const
{
	return m_window.getSize().y/2 + unitsToPixelsY(y);
}

sf::Vector2f Renderer::worldToScreen(sf::Vector2f const& vec) const
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

