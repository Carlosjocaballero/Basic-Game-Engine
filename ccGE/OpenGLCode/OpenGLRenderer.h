#pragma once

#include "RendererImplementation.h"

namespace ccGE {
	class OpenGLRendered : public RendererImplementation {
	public:
		virtual void Draw(Picture& pic, int x, int y, int z, Shader& shader) override;
	private:
	};
}
