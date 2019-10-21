#pragma once

namespace Samurai
{
	class Timestep
	{
	public:
		Timestep(float value = 0.00f) : time(value)
		{

		}

		operator float() const
		{
			return time;
		}

		float GetSeconds() const
		{
			return time;
		}

		float GetMilliseconds() const
		{
			return time * 1000.00f;
		}

	private:
		float time = 0.00f;
	};
}