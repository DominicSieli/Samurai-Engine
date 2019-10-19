#pragma once

#include "PCH.h"
#include "spdlog/spdlog.h"
#include "Samurai/Core/Core.h"

#ifdef SAMURAI_BUILD_DLL
	#define LOGGER SamuraiLogger()
#else
	#define LOGGER ClientLogger()
#endif

namespace Samurai
{
	class SAMURAI_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& SamuraiLogger() { return sPtr_SamuraiLogger; }
		inline static std::shared_ptr<spdlog::logger>& ClientLogger() { return sPtr_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> sPtr_SamuraiLogger;
		static std::shared_ptr<spdlog::logger> sPtr_ClientLogger;
	};
}

#define LOG_TRACE(...)        ::Samurai::Log::LOGGER->trace(__VA_ARGS__)
#define LOG_INFO(...)         ::Samurai::Log::LOGGER->info(__VA_ARGS__)
#define LOG_WARN(...)         ::Samurai::Log::LOGGER->warn(__VA_ARGS__)
#define LOG_ERROR(...)        ::Samurai::Log::LOGGER->error(__VA_ARGS__)
#define LOG_CRITICAL(...)     ::Samurai::Log::LOGGER->critical(__VA_ARGS__)