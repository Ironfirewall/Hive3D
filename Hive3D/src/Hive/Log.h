#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Hive {
	class HAPI Log
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
#define HV_CORE_TRACE(...)    ::Hive::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define HV_CORE_INFO(...)     ::Hive::Log::GetCoreLogger()->info(__VA_ARGS__)
#define HV_CORE_DEBUG(...)    ::Hive::Log::GetCoreLogger()->debug(__VA_ARGS__)
#define HV_CORE_WARN(...)     ::Hive::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define HV_CORE_ERROR(...)    ::Hive::Log::GetCoreLogger()->error(__VA_ARGS__)
#define HV_CORE_FATAL(...)    ::Hive::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define HV_CLIENT_TRACE(...)  ::Hive::Log::GetClientLogger()->trace(__VA_ARGS__)
#define HV_CLIENT_INFO(...)   ::Hive::Log::GetClientLogger()->info(__VA_ARGS__)
#define HV_CLIENT_DEBUG(...)  ::Hive::Log::GetClientLogger()->debug(__VA_ARGS__)
#define HV_CLIENT_WARN(...)   ::Hive::Log::GetClientLogger()->warn(__VA_ARGS__)
#define HV_CLIENT_ERROR(...)  ::Hive::Log::GetClientLogger()->error(__VA_ARGS__)
#define HV_CORE_FATAL(...)    ::Hive::Log::GetCoreLogger()->fatal(__VA_ARGS__)

