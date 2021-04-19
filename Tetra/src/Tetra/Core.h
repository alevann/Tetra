#pragma once

/**
 * __declspec() is limited to windows, which is why even tho we only still support
 * one platform, the window macro is defined.
 */
#ifdef TR_PLATFORM_WINDOWS

#if TR_DYNAMIC_LINK
	/**
	 * Has been defined in Tetra's build properties, but not in Sandbox's.
	 * This means it'll export when building the DLL and import when building the Sandbox.
	 *
	 * Tetra -> Properties -> C/C++ -> Preprocessor Definitions
	 */
	#ifdef TR_BUILD_DLL
		#define TETRA_API __declspec(dllexport)
	#else
		#define TETRA_API __declspec(dllimport)
	#endif
#else
	#define TETRA_API
#endif

#else
	#error Tetra only supports windows, for now.
#endif

#ifdef TR_DEBUG
	#define TR_ENABLE_ASSERT
#endif

#ifdef TR_ENABLE_ASSERT
	#define TR_ASSERT(x, ...) { if(!(x)) { TR_ERROR("Assertion failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define TR_CORE_ASSERT(x, ...) { if(!(x)) { TR_CORE_ERROR("Assertion failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define TR_ASSERT(x, ...)
	#define TR_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

#define TR_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)