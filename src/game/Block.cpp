#include "Block.hpp"

using namespace falksalt;

Block::Block(int layer, float x)
	: m_layer(layer), m_x(x), m_isDestroyed(false)
{
}

Block::Block()
	: m_layer(0), m_x(0), m_isDestroyed(true)
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

Collision Block::collides(glm::vec2 start, glm::vec2 end)
{
	if(isDestroyed())
		return NoCollision;

	glm::vec4 rect(getX(), getY(), Block::Width, Block::Height);
	auto collision = falksalt::collides(rect, start, end);
	collision.object = this;
	return collision;
}

bool Block::isDestroyed() const
{
	return m_isDestroyed;
}

int Block::destroy()
{
	m_isDestroyed = true;
	return getScore();
}

int Block::getScore() const
{
	return m_layer + 1;
}

