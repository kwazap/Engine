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

#define BIT(x) (x << 1)