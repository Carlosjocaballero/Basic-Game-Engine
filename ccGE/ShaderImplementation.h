#pragma once

namespace ccGE {
	class ShaderImplementation {
	public:
		virtual void Activate() = 0;

		virtual void ProvideValues(const std::string& valueName, const std::vector<float>& vals) = 0;
		virtual void ProvideValues(std::string&& valueName, std::vector<float>&& vals) = 0;

		virtual ~ShaderImplementation() {};
	};
}
