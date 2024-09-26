#pragma once

#ifdef BD_PLATFORM_WINDOWS
	#ifdef BD_BUILD_DLL
		#define BDE_API __declspec(dllexport)
	#else
		#define BDE_API __declspec(dllimport)
	#endif
#else
	#error BaDev Engine only supports Window OS
#endif 

