#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"

namespace Samurai
{
	class SAMURAI_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return sPtr_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return sPtr_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> sPtr_CoreLogger;
		static std::shared_ptr<spdlog::logger> sPtr_ClientLogger;
	};
}

#define SAMURAI_TRACE(...)    ::Samurai::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define SAMURAI_INFO(...)     ::Samurai::Log::GetCoreLogger()->info(__VA_ARGS__)
#define SAMURAI_WARN(...)     ::Samurai::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define SAMURAI_ERROR(...)    ::Samurai::Log::GetCoreLogger()->error(__VA_ARGS__)
#define SAMURAI_CRITICAL(...) ::Samurai::Log::GetCoreLogger()->critical(__VA_ARGS__)

#define LOG_TRACE(...)        ::Samurai::Log::GetClientLogger()->trace(__VA_ARGS__)
#define LOG_INFO(...)         ::Samurai::Log::GetClientLogger()->info(__VA_ARGS__)
#define LOG_WARN(...)         ::Samurai::Log::GetClientLogger()->warn(__VA_ARGS__)
#define LOG_ERROR(...)        ::Samurai::Log::GetClientLogger()->error(__VA_ARGS__)
#define LOG_CRITICAL(...)     ::Samurai::Log::GetClientLogger()->critical(__VA_ARGS__)