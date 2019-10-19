#include "Samurai.h"

namespace SandboxGame
{
	class Game : public Samurai::Game
	{
	public:
		Game()
		{
			LOG_INFO("Game Initialized");
		}

		~Game()
		{

		}
	};
}

Samurai::Game* Samurai::CreateGame()
{
	return new SandboxGame::Game();
}