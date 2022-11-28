#pragma once
#include "ccGEUtil.h"
#include "Shader.h"
#include "Picture.h"
#include "RendererImplementation.h";

namespace ccGE {
	class CCGE_API Renderer 
	{
	public:

		static void Init();
		
		static void Draw(Picture& pic, int x, int y, int z, Shader& shader = mDefaultShader);


	private:
		inline static Renderer* mInstance{ nullptr };

		RendererImplementation* mImplementation;

		Renderer();

		inline static Shader mDefaultShader{ "Assets/Shaders/defaultCCGEVertex.glsl",
		"Assets/Shaders/defaultCCGEFragment.glsl" };
	};
}
