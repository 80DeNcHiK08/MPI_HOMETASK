#pragma once

#ifdef TREEFUNCS_EXPORTS
#define TREEFUNCS_API __declspec(dllexport)
#else
#define TREEFUNCS_API __declspec(dllimport)
#endif

extern "C" TREEFUNCS_API void fibonacci_init(
	const unsigned long long a, const unsigned long long b);


