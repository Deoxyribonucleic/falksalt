#pragma once

namespace falksalt
{
	class PadController final
	{
	public:
		PadController();
		
		float getInputVelocity();
		void update();

	private:
		float m_inputVelocity;
	};
}

