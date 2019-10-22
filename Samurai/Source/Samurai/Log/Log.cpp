#include "PCH.h"
#include "Samurai/Log/Log.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Samurai
{
	using spdLogger = std::shared_ptr<spdlog::logger>;

	spdLogger Log::samuraiLogger;
	spdLogger Log::clientLogger;

	void Log::Initialize()
	{
		spdlog::set_pattern("%^[%T] %n: %v%$");
		samuraiLogger = spdlog::stdout_color_mt("SAMURAI");
		clientLogger = spdlog::stdout_color_mt("APPLICATION");
	}
}