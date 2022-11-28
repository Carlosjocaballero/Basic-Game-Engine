#include "pch.h"
#include "Renderer.h"

namespace ccGE {
	void Renderer::Init()
	{
		if (mInstance != nullptr) {
			mInstance = new Renderer;
		}
	}

	void Renderer::Draw(Picture& pic, int x, int y, int z, Shader& shader)
	{
		mImplementation->Draw(pic, x, y, z, shader);
	}

	Renderer::Renderer()
	{
#ifdef CCGE_OPENGL
		mImplementation = new OpenGLRenderer{};
#else
		#OpenGL_is_the_only_option_right_now
#endif
	}


}