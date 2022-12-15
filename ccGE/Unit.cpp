#include "pch.h"
#include "Unit.h"

namespace ccGE
{
	Unit::Unit(const std::string& picFile) : mPicture(picFile)
	{
	}

	Unit::Unit(std::string&& picFile): mPicture(picFile)
	{
	}

	void Unit::setCoord(int x, int y, int z)
	{
		mXcoord = x;
		mYcoord = y;
		mZcoord = z;
	}

	int Unit::ChangeX(int xDiff)
	{
		mXcoord += xDiff;
		return mXcoord;
	}

	int Unit::ChangeY(int yDiff)
	{
		mYcoord += yDiff;
		return mYcoord;
	}

	int Unit::GetX() const
	{
		return mXcoord;
	}

	int Unit::GetY() const
	{
		return mYcoord;
	}

	int Unit::GetZ() const
	{
		return mZcoord;
	}

	Picture Unit::getPicture() const
	{
		return mPicture;
	}

	bool Unit::OverlapsWith(const Unit& other) const
	{
		int oneLeft{ GetX() };
		int oneRight{ GetX() + mPicture.GetWidth() };
		int anotherLeft{ other.GetX() };
		int anotherRight{ other.GetX() + other.mPicture.GetHeight() };

		int oneBottom{ GetY() };
		int oneTop{ GetY() + mPicture.GetHeight() };
		int anotherBottom{ other.GetY() };
		int anotherTop{ other.GetY() + other.mPicture.GetHeight() };

		bool collideX{ false };
		if ((oneLeft <= anotherLeft && anotherLeft <= oneRight) ||
			(anotherLeft <= oneLeft && oneLeft <= anotherRight))
			collideX = true;

		bool collideY{ false };
		if ((oneBottom <= anotherBottom && anotherBottom <= oneTop) ||
			(anotherBottom <= oneBottom && oneBottom <= anotherTop))
			collideY = true;

		return collideX && collideY;
	}




}