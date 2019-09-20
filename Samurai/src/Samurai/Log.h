#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Samurai
{
	class SAMURAI_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// Core log macros
#define SAMURAI_CORE_TRACE(...)    ::SAMURAI::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define SAMURAI_CORE_INFO(...)     ::SAMURAI::Log::GetCoreLogger()->info(__VA_ARGS__)
#define SAMURAI_CORE_WARN(...)     ::SAMURAI::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define SAMURAI_CORE_ERROR(...)    ::SAMURAI::Log::GetCoreLogger()->error(__VA_ARGS__)
#define SAMURAI_CORE_CRITICAL(...) ::SAMURAI::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client log macros
#define SAMURAI_TRACE(...)         ::SAMURAI::Log::GetClientLogger()->trace(__VA_ARGS__)
#define SAMURAI_INFO(...)          ::SAMURAI::Log::GetClientLogger()->info(__VA_ARGS__)
#define SAMURAI_WARN(...)          ::SAMURAI::Log::GetClientLogger()->warn(__VA_ARGS__)
#define SAMURAI_ERROR(...)         ::SAMURAI::Log::GetClientLogger()->error(__VA_ARGS__)
#define SAMURAI_CRITICAL(...)      ::SAMURAI::Log::GetClientLogger()->critical(__VA_ARGS__)
