#include "Samurai.h"

namespace Sandbox
{
	class Application : public Samurai::Application
	{
	public:
		Application()
		{
			LOG_SUCCESS("Application Initialized")
		}

		~Application()
		{

		}
	};
}

Samurai::Application* Samurai::CreateApplication()
{
	return new Sandbox::Application();
}