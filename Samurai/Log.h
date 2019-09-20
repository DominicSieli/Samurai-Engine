#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"

namespace Samurai
{
	class SANURAI_API Log
	{
	public:
		Log();
		~Log();

		static void Init();
	};
}