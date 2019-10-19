#pragma once

#ifdef SAMURAI_PLATFORM_WINDOWS

extern Samurai::Game* game = Samurai::CreateGame();

int main(int argc, char** argv)
{
	game->Run();
	delete game;
}

#endif