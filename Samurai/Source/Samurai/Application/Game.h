#pragma once

#include "Samurai/Core/Core.h"

namespace Samurai
{
	class SAMURAI_API Game
	{
	public:
		Game();
		virtual ~Game();

		void Run();
	};

	Game* CreateGame();
}