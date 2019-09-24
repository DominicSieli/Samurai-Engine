#pragma once

#include <memory>

#ifdef SAMURAI_PLATFORM_WINDOWS
	#ifdef SAMURAI_BUILD_DLL
		#define SAMURAI_API __declspec(dllexport)
	#else
		#define SAMURAI_API __declspec(dllimport)
	#endif
	
	#else 
	#error Samurai is Windows only!
#endif