#pragma once

#include "PCH.h"
#include "spdlog/spdlog.h"
#include "Samurai/Core/Core.h"

namespace Samurai
{
	class SAMURAI_API Log
	{
	public:
		static void Initialize();
		using spdLogger = std::shared_ptr<spdlog::logger>;

		inline static spdLogger& SamuraiLogger()
		{
			return samuraiLogger;
		}

		inline static spdLogger& ClientLogger()
		{
			return clientLogger;
		}

	private:
		static spdLogger samuraiLogger;
		static spdLogger clientLogger;
	};
}

#ifdef SAMURAI_DEBUG
	#ifdef SAMURAI_BUILD_DLL
		#define LOG SamuraiLogger()
	#else
		#define LOG ClientLogger()
	#endif
	
	#define INITIALIZE_LOGGER ::Samurai::Log::Initialize();
	
	#define LOG_TRACE(...)        ::Samurai::Log::LOG->trace(__VA_ARGS__);
	#define LOG_INFO(...)         ::Samurai::Log::LOG->info(__VA_ARGS__);
	#define LOG_WARN(...)         ::Samurai::Log::LOG->warn(__VA_ARGS__);
	#define LOG_ERROR(...)        ::Samurai::Log::LOG->error(__VA_ARGS__);
	#define LOG_CRITICAL(...)     ::Samurai::Log::LOG->critical(__VA_ARGS__);
#else
	#define INITIALIZE_LOGGER
	
	#define LOG_TRACE(...)
	#define LOG_INFO(...)
	#define LOG_WARN(...)
	#define LOG_ERROR(...)
	#define LOG_CRITICAL(...)
#endif