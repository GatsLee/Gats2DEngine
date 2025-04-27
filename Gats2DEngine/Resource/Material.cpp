#include "Headers/pch.h"
#include "Material.h"
#include "Resource/WShader.h"
#include "Resource/WTexture.h"

Material::Material(): ResourceBase(ResourceType::Material)
{
	mType = ResourceType::Material;
	mColor = sf::Color::White;
	mBlendMode = sf::BlendAlpha;
	mShader = nullptr;
	mTexture = RESOURCES->Get<WTexture>(L"DefaultTexture");
	mLoaded = true;
}

Material::Material(std::shared_ptr<WTexture> texture) :ResourceBase(ResourceType::Material)
{
	mType = ResourceType::Material;
	mColor = sf::Color::White;
	mBlendMode = sf::BlendAlpha;
	mShader = nullptr;
	mTexture = texture;
	mLoaded = true;
}

Material::~Material()
{
}

void Material::SetColor(const sf::Color& color)
{
	mColor = color;
}

void Material::SetAlpha(float alpha)
{
	mColor.a = static_cast<uint8>(alpha * 255);
}

void Material::SetBlendMode(sf::BlendMode mode)
{
	// sf::BlendAlpha : default
	// sf::BlendAdd : additive blending
	//sf::BlendMultiply : multiplicative blending
	//sf::BlendNone : no blending
}

void Material::SetShader(std::shared_ptr<WShader> shader)
{
	mShader = shader;
	if (mShader)
	{
		mShader->SetUniform("uColor", mColor);
	}
	else
	{
		mShader = nullptr;
	}
}

void Material::Apply(std::shared_ptr<sf::Sprite> sprite)
{
	sprite->setColor(mColor);
	sprite->setTexture(mTexture->GetNativeTexture(), true);
	if (mShader)
	{
		//
	}
	else
	{
		//
	}
}

const sf::Color& Material::GetColor() const
{
	return mColor;
}
