#include "pch.h"
#include "ccGEWindow.h"
#include "GLFWcode/GLFWimplementation.h"

namespace ccGE {

	ccGEWindow::ccGEWindow() {};
	
	void ccGEWindow::Init() 
	{
		if (mInstance == nullptr) 
		{
			mInstance = new ccGEWindow;

#ifdef CCGE_WINDOWS
			mInstance->mImplementation = new GLFWimplementation;
#elif defined CCGE_MAC
			mInstance->mImplementation = new GLFWimplementation;
#else
			mInstance->mImplementation = new GLFWimplementation;
#endif

		}
	}
	
	
	ccGEWindow* ccGEWindow::GetWindow()
	{
		return mInstance;
	}

	void ccGE::ccGEWindow::Create(int width, int height, const std::string& windowName)
	{
		mImplementation->Create(width, height, windowName);
		mWidth = width;
		mHeight = height;
	}

	void ccGEWindow::SwapBuffers()
	{
		mImplementation->SwapBuffers();
	}

	int ccGEWindow::GetWidth() const
	{
		return mWidth;
	}

	int ccGEWindow::GetHeight() const
	{
		return mHeight;
	}

	void ccGEWindow::SetKeyPressedCallback(const std::function<void(const KeyPressedEvent&)>& keyPressedCallback)
	{
		mImplementation->SetKeyPressedCallback(keyPressedCallback);
	}

	void ccGEWindow::SetKeyReleasedCallBack(const std::function<void(const KeyReleasedEvent&)>& keyReleasedCallback)
	{
		mImplementation->SetKeyReleasedCallback(keyReleasedCallback);
	}

}

