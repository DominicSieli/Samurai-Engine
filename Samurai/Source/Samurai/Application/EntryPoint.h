#pragma once

#ifdef PLATFORM_WINDOWS

extern Samurai::Application* application = Samurai::CreateApplication();

int main(int argc, char** argv)
{
	application->Run();
	delete application;
}

#endif