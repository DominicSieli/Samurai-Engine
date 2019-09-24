#include <Samurai.h>

class Sandbox : public Samurai::Application
{
public:
	Sandbox()
	{
		Samurai::Log::Init();
		//Samurai_CORE_WARN("Initialized Log!");
	}

	~Sandbox()
	{

	}
};

Samurai::Application* Samurai::CreateApplication()
{
	return new Sandbox();
}