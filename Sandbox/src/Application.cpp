#include <iostream>

namespace Samurai
{
	__declspec(dllimport) void Print();
}


void main()
{
	Samurai::Print();
	std::cin.get();
}