#pragma once

#include "ccGEUtil.h"
#include "Picture.h"

namespace ccGE 
{
	class CCGE_API Unit 
	{
	public:
		Unit(const std::string& picFile);
		Unit(std::string&& picFile);

		void setCoord(int x, int y, int z);

		int ChangeX(int xDiff);
		int ChangeY(int yDiff);
		
		int GetX() const;
		int GetY() const;
		int GetZ() const;
		Picture getPicture() const;

		bool OverlapsWith(const Unit& other) const;

	private:	
		Picture mPicture;
		int mXcoord{ 0 };
		int mYcoord{ 0 };
		int mZcoord{ 0 };
		
		friend class Renderer;
	};
}
