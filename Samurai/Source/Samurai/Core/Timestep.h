#pragma once

namespace Samurai
{
	class Timestep
	{
	private:
		float time = 0.00f;

	public:
		Timestep(float value = 0.00f)
			: time(value)
		{

		}

		float GetSeconds() const
		{
			return time;
		}

		float GetMilliseconds() const
		{
			return time * 1000.00f;
		}
	};
}