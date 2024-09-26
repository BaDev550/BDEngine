#pragma once

#include <memory.h>
#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace BDE_ApplicationCore {
	class BDE_API Log
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
#define BDE_CORE_TRACE(...) ::BDE_ApplicationCore::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define BDE_CORE_INFO(...)  ::BDE_ApplicationCore::Log::GetCoreLogger()->info(__VA_ARGS__)
#define BDE_CORE_WARN(...)  ::BDE_ApplicationCore::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define BDE_CORE_ERROR(...) ::BDE_ApplicationCore::Log::GetCoreLogger()->error(__VA_ARGS__)
#define BDE_CORE_FATAL(...) ::BDE_ApplicationCore::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define BDE_TRACE(...) ::BDE_ApplicationCore::Log::GetClientLogger()->trace(__VA_ARGS__)
#define BDE_INFO(...)  ::BDE_ApplicationCore::Log::GetClientLogger()->info(__VA_ARGS__)
#define BDE_WARN(...)  ::BDE_ApplicationCore::Log::GetClientLogger()->warn(__VA_ARGS__)
#define BDE_ERROR(...) ::BDE_ApplicationCore::Log::GetClientLogger()->error(__VA_ARGS__)
#define BDE_FATAL(...) ::BDE_ApplicationCore::Log::GetClientLogger()->fatal(__VA_ARGS__)