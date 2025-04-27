#include "Headers\pch.h"
#include "WShader.h"

WShader::WShader()
	:ResourceBase(ResourceType::WShader)
{
	mShader = std::make_shared<sf::Shader>();
}

WShader::~WShader()
{
}

bool WShader::LoadFromFile(const std::wstring& vertexPath, const std::wstring& fragmentPath)
{
	std::wstring fullVertexPath = mBasePath + vertexPath;
	std::wstring fullFragmentPath = mBasePath + fragmentPath;
	return mShader->loadFromFile(fullVertexPath, fullFragmentPath);
}

void WShader::SetUniform(const std::string& name, float value)
{
	mShader->setUniform(name, value);
}

void WShader::SetUniform(const std::string& name, const sf::Vector2f& value)
{
	mShader->setUniform(name, sf::Glsl::Vec2(value.x, value.y));
}

void WShader::SetUniform(const std::string& name, const sf::Color& value)
{
	mShader->setUniform(name, sf::Glsl::Vec4(value.r / 255.f, value.g / 255.f, value.b / 255.f, value.a / 255.f));
}

void WShader::SetUniform(const std::string& name, const sf::Texture& value)
{
	mShader->setUniform(name, value);
}
