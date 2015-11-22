#pragma once


namespace falksalt
{
	class Pad final
	{
	public:
		Pad();

		static const constexpr float VerticalPosition = 0.7f; 
		
		float getPosition() const;
		void setVelocity(float vel);

		void update(float delta);
		
	private:
		float m_position;
		float m_velocity;
	};
}

