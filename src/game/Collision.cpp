#define GLM_SWIZZLE

#include "Collision.hpp"

#include <algorithm>
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

const Collision falksalt::NoCollision = {false, Side::Up, {}, nullptr};

Collision falksalt::intersects(glm::vec2 start1, glm::vec2 end1,
	glm::vec2 start2, glm::vec2 end2)
{
	auto dir1 = glm::normalize(end1 - start1);
	auto dir2 = glm::normalize(end2 - start2);

	// If the lines are parallel, they do not intersect
	if(glm::abs(glm::dot(dir1, dir2)) == 1.f)
		return NoCollision;

	Collision collision;

	if(dir1.x == 0.f)
	{
		float k = dir2.y / dir2.x;
		float m = start2.y - k * start2.x;

		collision.where.x = start1.x;
		collision.where.y = k*start1.x + m;
	}
	else if(dir2.x == 0.f)
	{
		float k = dir1.y / dir1.x;
		float m = start1.y - k * start1.x;

		collision.where.x = start2.x;
		collision.where.y = k*start2.x + m;
	}
	else
	{
		float k1 = dir1.y / dir1.x;
		float m1 = start1.y - k1 * start1.x;

		float k2 = dir2.y / dir2.x;
		float m2 = start2.y - k2 * start2.x;
		
		float x = (m1 - m2) / (k2 - k1);
		collision.where.x = x;
		collision.where.y = k1*x + m1;
	}

	 collision.collision = isOnLineSegment(start1, end1, collision.where) &&
			isOnLineSegment(start2, end2, collision.where);

	 return collision;
}

Collision falksalt::closest(glm::vec2 to, std::vector<Collision> const& collisions)
{
	// Filter out non-collisions
	auto tmp = collisions;
	tmp = std::vector<Collision>(tmp.begin(),
			std::remove_if(tmp.begin(), tmp.end(),
			[](Collision const& collision)
			{ return !collision.collision; }));

	if(tmp.empty())
		return NoCollision;

	// Return collision closest to start point
	return *std::min_element(tmp.begin(), tmp.end(),
		[&to](Collision const& a, Collision const& b)
		{
			return glm::length(a.where - to) < glm::length(b.where - to);
		});
}

Collision falksalt::collides(glm::vec4 rect,
	glm::vec2 start, glm::vec2 end)
{
	std::vector<Collision> collisions(4);

	collisions[0] = intersects(start, end, rect.xy(), rect.xy() + glm::vec2(rect.z, 0));
	collisions[0].side = Side::Up;

	collisions[1] = intersects(start, end, rect.xy() + glm::vec2(0, rect.w),
		rect.xy() + rect.zw());
	collisions[1].side = Side::Down;

	collisions[2] = intersects(start, end, rect.xy(), rect.xy() + glm::vec2(0, rect.w));
	collisions[2].side = Side::Left;

	collisions[3] = intersects(start, end, rect.xy() + glm::vec2(rect.z, 0),
			rect.xy() + rect.zw());
	collisions[3].side = Side::Right;

	return closest(start, collisions);
}

