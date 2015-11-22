#pragma once 
#include <glm/glm.hpp>

namespace falksalt
{
	enum class Collision : int
	{
		None = 0, Up, Right, Down, Left
	};

	bool isOnLineSegment(glm::vec2 start, glm::vec2 end, glm::vec2 point);
	bool intersects(glm::vec2 start1, glm::vec2 end1,
		glm::vec2 start2, glm::vec2 end2, glm::vec2& where);
	Collision collides(glm::vec4 rect,
		glm::vec2 start, glm::vec2 end, glm::vec2& where);
}

