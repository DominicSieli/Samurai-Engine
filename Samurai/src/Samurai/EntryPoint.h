#pragma once

#ifdef SAMURAI_PLATFORM_WINDOWS

extern Samurai::Application* Samurai::CreateApplication();

int main(int argc, char** argv)
{
	printf("Welcome Samurai!");
	auto app = Samurai::CreateApplication();
	app->Run();
	delete app;
}

#endif
