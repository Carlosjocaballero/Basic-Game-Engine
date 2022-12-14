#pragma once

#include "pch.h"
#include "ccGEUtil.h"

constexpr int FRAMES_PER_SECOND = 60;

namespace ccGE  
{
	class CCGE_API ccGEApp
	{
	public:
		ccGEApp();
		virtual void onUpdate();
		void Run();
	private: 
		std::chrono::milliseconds mFrameDuration{ 1000 / FRAMES_PER_SECOND };
		std::chrono::steady_clock::time_point mNextFrameTime;
	};
}


