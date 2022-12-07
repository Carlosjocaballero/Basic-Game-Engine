#pragma once
#include "ccGEUtil.h"
#include "pch.h"
#include "WindowImplementation.h"

namespace ccGE
{
	class CCGE_API ccGEWindow 
	{
	public:

		static void Init();
		static ccGEWindow* GetWindow();

		virtual void Create(int width, int height, const std::string& windowName);
		virtual void SwapBuffers();

		int GetWidth() const;
		int GetHeight() const;

		
	private:
		ccGEWindow();

		inline static ccGEWindow* mInstance{ nullptr };

		WindowImplementation* mImplementation{ nullptr };

		int mWidth{ 0 };
		int mHeight{ 0 };
	};
}
