#pragma once 
#include <glm/glm.hpp>

#include <vector>

namespace falksalt
{
	enum class Side
	{
		Up, Right, Down, Left
	};
	
	struct Collision
	{
		bool collision;
		Side side;
		glm::vec2 where;
		void* object;
	};

	extern const Collision NoCollision;

	bool isOnLineSegment(glm::vec2 start, glm::vec2 end, glm::vec2 point);
	Collision intersects(glm::vec2 start1, glm::vec2 end1,
		glm::vec2 start2, glm::vec2 end2);
	Collision closest(glm::vec2 to, std::vector<Collision> const& collisions);
	Collision collides(glm::vec4 rect,
		glm::vec2 start, glm::vec2 end);
}

