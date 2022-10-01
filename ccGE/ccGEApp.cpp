#include "pch.h"
#include "ccGEApp.h"
#include "CCGEUtil.h"

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
