#include "Renderer.hpp"

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

