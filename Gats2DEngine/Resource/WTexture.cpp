#include "Headers/pch.h"
#include "WTexture.h"

WTexture::WTexture()
	: ResourceBase(ResourceType::WTexture)
{
}

WTexture::WTexture(const std::wstring& path, bool sRgb, const sf::IntRect& area)
	: ResourceBase(ResourceType::WTexture),
	mPath(path)
{
	std::wstring fullPath = mBasePath + path;
	if (LoadFromFile(fullPath, sRgb, area) == false)
	{
		DEBUG_PRINT_A1("Failed to load texture from file: %ls", fullPath.c_str());
		assert(false);
	}
	else
	{
		mLoaded = true;
	}
}

WTexture::~WTexture()
{
}

bool WTexture::LoadFromFile(const std::wstring& path, bool sRgb, const sf::IntRect& area)
{
	std::filesystem::path filePath(path);

	if (filePath.extension() == L".png"
		|| filePath.extension() == L".jpg"
		|| filePath.extension() == L".jpeg"
		|| filePath.extension() == L".bmp")
	{
		mTexture = std::make_shared<sf::Texture>();
		if (!mTexture->loadFromFile(path, sRgb, area))
		{
			return false;
		}
		if (sRgb)
		{
			mTexture->setSmooth(true);
			mTexture->setRepeated(false);
		}
		else
		{
			mTexture->setSmooth(false);
			mTexture->setRepeated(true);
		}
		mLoaded = true;
		return true;
	}
	else
	{
		return false;
	}
}
