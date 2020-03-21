#pragma once

#ifdef PLATFORM_WINDOWS
	#ifdef BUILD_DLL
		#define SAMURAI_API __declspec(dllexport)
	#else
		#define SAMURAI_API __declspec(dllimport)
	#endif
#endif