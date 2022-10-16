#include "pch.h"
#include "ccGEWindow.h"
#include "GLFWcode/GLFWimplementation.h"

namespace ccGE {
	
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
	
	
	WindowImplementation* ccGEWindow::GetWindow()
	{
		return mInstance->mImplementation;
	}

	void ccGE::ccGEWindow::Create(int width, int height, const std::string& windowName)
	{
		mImplementation->Create(width, height, windowName);
	}

	void ccGEWindow::SwapBuffers()
	{
		mImplementation->SwapBuffers();
	}

}

