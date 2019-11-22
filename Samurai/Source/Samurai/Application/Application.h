#pragma once

#include "Samurai/Core/Core.h"

namespace Samurai
{
	class SAMURAI_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	Application* CreateApplication();
}