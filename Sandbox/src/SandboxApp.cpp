#include <Samurai.h>

class Sandbox : public Samurai::Application
{
public:
	Sandbox()
	{
		LOG_INFO("Application Initialized");
	}

	~Sandbox()
	{

	}
};

Samurai::Application* Samurai::CreateApplication()
{
	return new Sandbox();
}