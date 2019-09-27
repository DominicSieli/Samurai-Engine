#include "Log.h"
#include "Application.h"

namespace Samurai
{
	Application::Application()
	{
		Samurai::Log::Init();
	};

	Application::~Application()
	{

	};

	void Application::Run()
	{
		while(true);
	}
}