#pragma once

#include "../RendererImplementation.h"

namespace ccGE {
	class OpenGLRenderer : public RendererImplementation {
	public:
		OpenGLRenderer();
		virtual void Draw(Picture& pic, int x, int y, int z, Shader& shader) override;
		virtual void Clear() override;
	};
}
