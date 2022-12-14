#pragma once

#include "ccGEUtil.h"

namespace ccGE 
{
	class CCGE_API KeyPressedEvent 
	{
	public:
		KeyPressedEvent(int codeOfKey);
		KeyPressedEvent() = delete;

		int GetKeyCode() const;

	private:
		int mKeyCode;
	};

	class CCGE_API KeyReleasedEvent
	{
	public:
		KeyReleasedEvent(int codeOfKey);
		KeyReleasedEvent() = delete;

		int GetKeyCode() const;
	private:
		int mKeyCode;
	};
}