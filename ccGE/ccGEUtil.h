#pragma once

#define START_CCGE_GAME(GameClass) \
	int main() \
	{ \
		GameClass  __ccGE__game;\
		__ccGE__game.Run();\
		return 0;\
	}

#ifdef CCGE_WINDOWS
	#ifdef CCGE_LIB 
		#define CCGE_API __declspec(dllexport)
	#else
		#define CCGE_API __declspec(dllimport)
	#endif
#else 
	#define CCGE_API
#endif

#ifdef CCGE_DEBUG
	#define CCGE_LOG(x) std::cout << x << std::endl;
#else
	#define CCGE_LOG(x)
#endif