#pragma once

#include "pch.h"
#include "ccGEUtil.h"

namespace ccGE  
{
	class CCGE_API ccGEApp
	{
	public:
		virtual void onUpdate();
		void Run();
	private: 
		std::chrono::milliseconds mFrameDuration;
	};
}


