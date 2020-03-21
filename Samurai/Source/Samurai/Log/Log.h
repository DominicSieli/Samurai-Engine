#pragma once

#ifdef DEBUG
	#include "PCH.h"
	
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	
	#define LOG_MESSAGE(...) SetConsoleTextAttribute(console, 15); std::cout << (__VA_ARGS__) << std::endl;
	#define LOG_SUCCESS(...) SetConsoleTextAttribute(console, 10); std::cout << (__VA_ARGS__) << std::endl;
	#define LOG_WARNING(...) SetConsoleTextAttribute(console, 14); std::cout << (__VA_ARGS__) << std::endl;
	#define LOG_ERROR(...)   SetConsoleTextAttribute(console, 12); std::cout << (__VA_ARGS__) << std::endl;
#endif