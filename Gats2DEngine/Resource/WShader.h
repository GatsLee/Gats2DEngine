#pragma once
#include "ResourceBase.h"
class WShader : public ResourceBase
{
public:
	WShader();
	~WShader();

public:
	bool LoadFromFile(const std::wstring& vertexPath, const std::wstring& fragmentPath);
	void SetUniform(const std::string& name, float value);
	void SetUniform(const std::string& name, const sf::Vector2f& value);
	void SetUniform(const std::string& name, const sf::Color& value);
	void SetUniform(const std::string& name, const sf::Texture& value);

	sf::Shader* GetNativeShader() { return mShader.get(); }

private:
	std::wstring mBasePath = L"../Asset/Shader/";

private:
	std::wstring mPath;
	std::shared_ptr<sf::Shader> mShader;
};

