#pragma once

#include "Uncopiable.hpp"

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


namespace falksalt
{
	class Renderer final : Uncopiable
	{
	public:
		Renderer();
		~Renderer();

		sf::Window& getWindow();

		void beginRender();
		void finishRender();

	private:
		sf::RenderWindow m_window;
	};
}

