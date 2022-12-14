#pragma once
#include "ccGEUtil.h"
#include "pch.h"
#include "WindowImplementation.h"
#include "Event.h"

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

		void SetKeyPressedCallback(const std::function<void(const KeyPressedEvent&)>& keyPressedCallback);
		void SetKeyReleasedCallBack(const std::function<void(const KeyReleasedEvent&)>& keyReleasedCallback);

		
	private:
		ccGEWindow();

		inline static ccGEWindow* mInstance{ nullptr };

		WindowImplementation* mImplementation{ nullptr };

		int mWidth{ 0 };
		int mHeight{ 0 };
	};
}
