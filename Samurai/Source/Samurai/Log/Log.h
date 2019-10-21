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

		inline static std::shared_ptr<spdlog::logger>& SamuraiLogger()
		{
			return sPtr_SamuraiLogger;
		}

		inline static std::shared_ptr<spdlog::logger>& ClientLogger()
		{
			return sPtr_ClientLogger;
		}

	private:
		static std::shared_ptr<spdlog::logger> sPtr_SamuraiLogger;
		static std::shared_ptr<spdlog::logger> sPtr_ClientLogger;
	};
}

#ifdef SAMURAI_DEBUG
	#ifdef SAMURAI_BUILD_DLL
		#define LOG SamuraiLogger()
	#else
		#define LOG ClientLogger()
	#endif
	
	#define INITIALIZE_LOG ::Samurai::Log::Initialize();
	
	#define LOG_TRACE(...)        ::Samurai::Log::LOG->trace(__VA_ARGS__);
	#define LOG_INFO(...)         ::Samurai::Log::LOG->info(__VA_ARGS__);
	#define LOG_WARN(...)         ::Samurai::Log::LOG->warn(__VA_ARGS__);
	#define LOG_ERROR(...)        ::Samurai::Log::LOG->error(__VA_ARGS__);
	#define LOG_CRITICAL(...)     ::Samurai::Log::LOG->critical(__VA_ARGS__);
#else
	#define INITIALIZE_LOG
	#define LOG_TRACE(...)
	#define LOG_INFO(...)
	#define LOG_WARN(...)
	#define LOG_ERROR(...)
	#define LOG_CRITICAL(...)
#endif