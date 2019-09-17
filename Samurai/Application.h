#pragma once

#include "Core.h"

namespace Samurai
{
	class SAMURAI_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};
}