#pragma once

#include <memory.h>
#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Tetra {

	// TODO: implement verbose log, which is output in a file

	class TETRA_API Log
	{
	public:
		
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() {
			return s_CoreLogger;
		}

		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() {
			return s_ClientLogger;
		}

	private:

		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;

	};


}

/* CORE LOGGING MACROS */
#define TR_CORE_CRIT(...)	::Tetra::Log::GetCoreLogger()->critical(__VA_ARGS__)
#define TR_CORE_ERROR(...)	::Tetra::Log::GetCoreLogger()->error(__VA_ARGS__)
#define TR_CORE_WARN(...)	::Tetra::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define TR_CORE_INFO(...)	::Tetra::Log::GetCoreLogger()->info(__VA_ARGS__)
#define TR_CORE_TRACE(...)	::Tetra::Log::GetCoreLogger()->trace(__VA_ARGS__)

/* CLIENT LOGGING MACROS */
#define TR_FATAL(...)	::Tetra::Log::GetClientLogger()->fatal(__VA_ARGS__)
#define TR_ERROR(...)	::Tetra::Log::GetClientLogger()->error(__VA_ARGS__)
#define TR_WARN(...)	::Tetra::Log::GetClientLogger()->warn(__VA_ARGS__)
#define TR_INFO(...)	::Tetra::Log::GetClientLogger()->info(__VA_ARGS__)
#define TR_TRACE(...)	::Tetra::Log::GetClientLogger()->trace(__VA_ARGS__)
