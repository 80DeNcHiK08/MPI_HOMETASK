#pragma once

#ifdef SIP.DATA_EXPORTS
#define TREEFUNCTIONS_API __declspec(dllexport)
#else
#define TREEFUNCTIONS_API __declspec(dllimport)
#endif

class TREEFUNCTIONS_API TreeFunctions {
public:
	TreeFunctions();
	~TreeFunctions();
};
