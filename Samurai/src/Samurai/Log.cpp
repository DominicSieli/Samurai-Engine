#include "Log.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Samurai
{
	std::shared_ptr<spdlog::logger> Log::sPtr_CoreLogger;
	std::shared_ptr<spdlog::logger> Log::sPtr_ClientLogger;

	void Log::Init()
	{
		spdlog::set_pattern("%^[%T] %n: %v%$");
		sPtr_CoreLogger = spdlog::stdout_color_mt("SAMURAI");
		sPtr_CoreLogger->set_level(spdlog::level::trace);

		sPtr_ClientLogger = spdlog::stdout_color_mt("APPLICATION");
		sPtr_ClientLogger->set_level(spdlog::level::trace);
	}
}