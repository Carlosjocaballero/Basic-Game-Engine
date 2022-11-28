#pragma once

#include "ccGEUtil.h"
#include "ShaderImplementation.h"
#include "pch.h"

namespace ccGE {
	class CCGE_API Shader 
	{
	public:
		Shader(const std::string& vertexFile, const std::string& fragmentShader);
		Shader(std::string&& vertexFile, std::string&& fragmentShader);

		void Active();


		void ProvideValues(const std::string& valueName, const std::vector<float>& vals);
		void ProvideValues(std::string&& valueName, const std::vector<float>& vals);

	private:
		ShaderImplementation* mImplementation;
	};
}
