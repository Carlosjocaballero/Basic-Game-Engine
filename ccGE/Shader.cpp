#include "pch.h"
#include "Shader.h"

namespace ccGE {
	void Shader::Active(){
		mImplementation->Activate();
	}

	void Shader::ProvideValues(const std::string& valueName, const std::vector<float>& vals)
	{
		mImplementation->ProvideFloatValues(valueName, vals);
	}

	void Shader::ProvideValues(std::string&& valueName, const std::vector<float>& vals)
	{
		mImplementation->ProvideFloatValues(valueName, vals);
	}



}