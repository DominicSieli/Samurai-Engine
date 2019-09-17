#include <Samurai.h>

class Sandbox : public Samurai::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

Samurai::Application* Samurai::CreateApplication()
{
	return new Sandbox();
}