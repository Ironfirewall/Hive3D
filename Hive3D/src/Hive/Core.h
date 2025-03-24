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

#define BIT(x) (1 << x)