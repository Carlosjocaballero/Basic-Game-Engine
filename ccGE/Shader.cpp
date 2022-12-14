#include "pch.h"
#include "Shader.h"
#include "OpenGLCode/OpenGLShader.h"

namespace ccGE {
	Shader::Shader(const std::string& vertexFile, const std::string& fragmentFile)
	{
#ifdef CCGE_OPENGL
		mImplementation = new OpenGLShader{vertexFile, fragmentFile};
#else
		#OpenGL_is_the_only_option_right_now
#endif
	}
	Shader::Shader(std::string&& vertexFile, std::string&& fragmentFile)
	{
#ifdef CCGE_OPENGL
		mImplementation = new OpenGLShader{ vertexFile, fragmentFile };
#else
		#OpenGL_is_the_only_option_right_now
#endif
	}
	void Shader::Active(){
		mImplementation->Activate();
	}

	void Shader::ProvideFloatValues(const std::string& valueName, const std::vector<float>& vals)
	{
		mImplementation->ProvideValues(valueName, vals);
	}

	void Shader::ProvideFloatValues(std::string&& valueName, std::vector<float>&& vals)
	{
		mImplementation->ProvideValues(valueName, vals);
	}



}