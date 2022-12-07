#pragma once
#include "../ShaderImplementation.h"

namespace ccGE {
	class OpenGLShader : public ShaderImplementation
	{
	public:
		OpenGLShader(const std::string& vertexFile, const std::string& fragmentFile);
		OpenGLShader(std::string&& vertexFile, std::string&& fragmentFile);

		virtual void Activate() override;

		virtual void ProvideValues(const std::string& valueName, const std::vector<float>& vals) override;
		virtual void ProvideValues(std::string&& valueName, std::vector<float>&& vals) override;

	private:
		unsigned int mShaderProg{ 0 };
	};
}