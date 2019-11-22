#include "PCH.h"
#include "Samurai/Log/Log.h"
#include "Samurai/Application/Application.h"

namespace Samurai
{
	Application::Application()
	{
		INITIALIZE_LOGGER
		LOG_INFO("Logging Initialized")
	};

	Application::~Application()
	{

	};

	void Application::Run()
	{
		while(true);
	}
}