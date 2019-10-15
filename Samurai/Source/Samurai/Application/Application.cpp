#include "PCH.h"
#include "Samurai/Log/Log.h"
#include "Samurai/Application/Application.h"

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