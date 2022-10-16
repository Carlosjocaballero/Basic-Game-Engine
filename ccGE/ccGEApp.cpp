#include "pch.h"
#include "ccGEApp.h"
#include "CCGEUtil.h"
#include "ccGEWindow.h"

namespace ccGE
{
	void ccGEApp::onUpdate() 
	{

	}

	void ccGEApp::Run() 
	{
		CCGE_LOG("CCGE Running..");

		ccGEWindow::Init();
		ccGEWindow::GetWindow->Create(600, 400, "TestWindow");




		while (true)
		{
			ccGEWindow::GetWindow->swapBuffers();

			onUpdate();
		}

		
	}
}
