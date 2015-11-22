#pragma once

#include "Uncopiable.hpp"

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


namespace falksalt
{
	class Pad;
	class Block;
	class Renderer final : Uncopiable
	{
	public:
		Renderer();
		~Renderer();

		sf::Window& getWindow();

		void beginRender();
		void finishRender();

		void render(Pad const& pad);
		void render(Block const& block);

	private:
		sf::RenderWindow m_window;

		float unitsToPixelsX(float x) const;
		float unitsToPixelsY(float y) const;

		float worldToScreenX(float x) const;
		float worldToScreenY(float y) const;
		sf::Vector2f worldToScreen(sf::Vector2f const& vec) const;

		sf::Color getBlockColor(int layer) const;
	};
}

