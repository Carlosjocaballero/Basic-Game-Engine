#include "pch.h"
#include "Renderer.h"
#include "OpenGLCode/OpenGLRenderer.h"

namespace ccGE {
	void Renderer::Init()
	{
		if (mInstance == nullptr) {
			mInstance = new Renderer;
		}
	}

	Renderer* Renderer::GetRenderer()
	{
		return mInstance;
	}

	void Renderer::Draw(Picture& pic, int x, int y, int z)
	{

		GetRenderer()->mImplementation->Draw(pic, x, y, z, GetRenderer()->mDefaultShader);
	}

	void Renderer::Draw(Picture& pic, int x, int y, int z, Shader& shader)
	{
		GetRenderer()->mImplementation->Draw(pic, x, y, z, shader);
	}

	void Renderer::Clear()
	{
		GetRenderer()->mImplementation->Clear();
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