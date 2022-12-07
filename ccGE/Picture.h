#pragma once
#include "pch.h"
#include "ccGEUtil.h"
#include "PictureImplementation.h"

namespace ccGE {
	class CCGE_API Picture
	{
	public:
		Picture(const std::string& sourceFile);

		// We use double reference to be able to accept a raw 
		// string inside the constructor
		Picture(const std::string&& sourceFile);


		int GetHeight() const;
		int GetWidth() const;

		void Activate();

	private:
		PictureImplementation* mImplementation{ nullptr };
	};
}
