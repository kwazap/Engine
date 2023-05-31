#pragma once

#ifdef EA_PLATFORM_WINDOWS
	#ifdef EA_BUILD_DLL
		#define ENGINEA_API __declspec(dllexport)
	#else
		#define ENGINEA_API __declspec(dllimport)
	#endif
#else
	#error EngineA only supports Windows!
#endif

#ifdef EA_ENABLE_ASSERTS
	#define EA_ASSERT(x, ...) { if (!(x)) {EA_ERROR("Assertion Failed: {0}", ___VA_ARGS__); __debugbreak(); } }
	#define EA_CORE_ASSERT(x, ...) { if (!(x)) {EA_CORE_ERROR("Assertion Failed: {0}", ___VA_ARGS__); __debugbreak(); } }
#else
	#define EA_ASSERT(x, ...)
	#define EA_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (x << 1)