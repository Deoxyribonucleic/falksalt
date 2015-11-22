#include "Collision.hpp"

#include <iostream>

using namespace falksalt;

bool falksalt::isOnLineSegment(glm::vec2 start, glm::vec2 end, glm::vec2 point)
{
	// IMPORTANT: This should probably logically include the endpoints, but
	// I think this might be more practical for collisions...
	// ALSO IMPORTANT: If things seem fleety, adjust the runes below.
	// Greetings from Epsilon.
	return (glm::length(point - start) + glm::length(end - point)) - 
		glm::length(start - end) < 0.000000001f && start != point; // && end != point;
}

bool falksalt::intersects(glm::vec2 start1, glm::vec2 end1,
	glm::vec2 start2, glm::vec2 end2, glm::vec2& where)
{
	auto dir1 = glm::normalize(end1 - start1);
	auto dir2 = glm::normalize(end2 - start2);

	// If the lines are parallel, they do not intersect
	if(glm::abs(glm::dot(dir1, dir2)) == 1.f)
		return false;

	if(dir1.x == 0.f)
	{
		float k = dir2.y / dir2.x;
		float m = start2.y - k * start2.x;

		where.x = start1.x;
		where.y = k*start1.x + m;
	}
	else if(dir2.x == 0.f)
	{
		float k = dir1.y / dir1.x;
		float m = start1.y - k * start1.x;

		where.x = start2.x;
		where.y = k*start2.x + m;
	}
	else
	{
		float k1 = dir1.y / dir1.x;
		float m1 = start1.y - k1 * start1.x;

		float k2 = dir2.y / dir2.x;
		float m2 = start2.y - k2 * start2.x;
		
		float x = (m1 - m2) / (k2 - k1);
		where.x = x;
		where.y = k1*x + m1;
	}

	return isOnLineSegment(start1, end1, where) &&
			isOnLineSegment(start2, end2, where);
}

//Collision collides(glm::vec4 rect,
//	glm::vec2 start, glm::vec2 end, glm::vec2& where)
Collision falksalt::collides(glm::vec4,
	glm::vec2, glm::vec2, glm::vec2&)
{
	return Collision::None;
}

