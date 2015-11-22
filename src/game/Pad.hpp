#pragma once


namespace falksalt
{
	class Pad final
	{
	public:
		Pad();

		static const constexpr float VerticalPosition = 3/4.f - 1/16.f; 
		static const constexpr float Width = 1/4.f; 
		static const constexpr float Height = 1/32.f;

		
		float getPosition() const;
		void setVelocity(float vel);

		void update(float delta);
		
	private:
		float m_position;
		float m_velocity;
	};
}

