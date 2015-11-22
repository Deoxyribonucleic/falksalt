#include "Block.hpp"

using namespace falksalt;

Block::Block(int layer, float x)
	: m_layer(layer), m_x(x)
{
}

Block::Block()
	: m_layer(0), m_x(0)
{
}

float Block::getX() const
{
	return m_x;
}

float Block::getY() const
{
	return TopBlock + (Layers - m_layer - 1) * Height;
}

int Block::getLayer() const
{
	return m_layer;
}

