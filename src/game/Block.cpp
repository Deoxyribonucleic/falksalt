#include "Block.hpp"

using namespace falksalt;

Block::Block(int layer, int index)
	: m_layer(layer), m_index(index), m_isDestroyed(false)
{
}

Block::Block()
	: m_layer(0), m_index(0), m_isDestroyed(true)
{
}

float Block::getX() const
{
	return m_index * Block::Width - 1.0f;
}

float Block::getY() const
{
	return TopBlock + (Layers - m_layer - 1) * Height;
}

int Block::getLayer() const
{
	return m_layer;
}

int Block::getIndex() const
{
	return m_index;
}

Collision Block::collides(glm::vec2 start, glm::vec2 end) const
{
	if(isDestroyed())
		return NoCollision;

	glm::vec4 rect(getX(), getY(), Block::Width, Block::Height);
	auto collision = falksalt::collides(rect, start, end);
	collision.object = CollisionObject::Block;
	collision.block = this;
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

