#pragma once

#include <memory>
#include "Core.h"
#include "spdlog/spdlog.h"

namespace EngineA {

	class ENGINEA_API Log
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

//core log macros
#define EA_CORE_TRACE(...)  ::EngineA::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define EA_CORE_INFO(...)   ::EngineA::Log::GetCoreLogger()->info(__VA_ARGS__)
#define EA_CORE_WARN(...)   ::EngineA::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define EA_CORE_ERROR(...)  ::EngineA::Log::GetCoreLogger()->error(__VA_ARGS__)
#define EA_CORE_FATAL(...)  ::EngineA::Log::GetCoreLogger()->fatal(__VA_ARGS__)

//client log macros
#define EA_TRACE(...)       ::EngineA::Log::GetClientLogger()->trace(__VA_ARGS__)
#define EA_INFO(...)        ::EngineA::Log::GetClientLogger()->info(__VA_ARGS__)
#define EA_WARN(...)        ::EngineA::Log::GetClientLogger()->warn(__VA_ARGS__)
#define EA_ERROR(...)       ::EngineA::Log::GetClientLogger()->error(__VA_ARGS__)
#define EA_FATAL(...)       ::EngineA::Log::GetClientLogger()->fatal(__VA_ARGS__)