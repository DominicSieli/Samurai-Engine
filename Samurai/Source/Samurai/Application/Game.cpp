#include "PCH.h"
#include "Samurai/Log/Log.h"
#include "Samurai/Application/Game.h"

namespace Samurai
{
	Game::Game()
	{
		Samurai::Log::Init();
		LOG_INFO("Logging Initialized");
	};

	Game::~Game()
	{

	};

	void Game::Run()
	{
		while(true);
	}
}