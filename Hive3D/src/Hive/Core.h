#pragma once

#ifdef HV_PLATFORM_WINDOWS
	#ifdef HV_BUILD_DLL
		#define HAPI __declspec(dllexport)
	#else
		#define HAPI __declspec(dllimport)
	#endif
#else
	#error Hive only supports Windows for now
#endif

#ifdef HV_ENABLED_ASSERTS
	#define HV_ASSERT(x, ...) { if(!x) { HV_ERROR("Assertion Failed: {0}", __VA__ARGS); __debugbreak(); } }
	#define HV_CORE_ASSERT(x, ...) { if(!x) { HV_CORE_ERROR("Assertion Failed: {0}", __VA__ARGS); __debugbreak(); } }
#else
	#define HV_ASSERT(x, ...);
	#define HV_CORE_ASSERT(x, ...);
#endif

#define BIT(x) (1 << x)