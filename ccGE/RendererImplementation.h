#pragma once
#include "Shader.h"
#include "Picture.h"

namespace ccGE {
	class RendererImplementation {
	public:
		virtual void Draw(Picture& pic, int x, int y, int z, Shader& shader) = 0;
	};
}
