#pragma once

#include "Application.h"

#ifdef SAMURAI_PLATFORM_WINDOWS

extern Samurai::Application* Samurai::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Samurai::CreateApplication();
	app->Run();
	delete app;
}

#endif