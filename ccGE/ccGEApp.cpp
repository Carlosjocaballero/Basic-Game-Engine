#include "ccGEApp.h"
#include "CCGEUtil.h"
#include <iostream>

namespace ccGE
{
	void ccGEApp::onUpdate() 
	{

	}

	void ccGEApp::Run() 
	{
		CCGE_LOG("CCGE Running..");
		while (true)
		{
			onUpdate();
		}
	}
}
