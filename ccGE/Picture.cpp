#include "pch.h"
#include "Picture.h"

namespace ccGE {
	Picture::Picture(const std::string& sourceFile)
	{
#ifdef CCGE_OPENGL
		mImplementation = new OpenGLPicture{sourceFile};
#else
		#OpenGL_is_the_only_option_right_now
#endif
	}

	Picture::Picture(const std::string&& sourceFile)
	{
#ifdef CCGE_OPENGL
		mImplementation = new OpenGLPicture{ sourceFile };
#else
		#OpenGL_is_the_only_option_right_now
#endif
	}
	int Picture::GetHeight() const
	{
		return mImplementation->getHeight();
	}
	int Picture::GetWidth() const
	{
		return mImplementation->getWidth();
	}
	void Picture::Activate()
	{
	}
}