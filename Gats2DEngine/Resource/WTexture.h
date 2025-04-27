#pragma once

#include "ResourceBase.h"

class WTexture : public ResourceBase
{
public:
	WTexture();
	WTexture(const std::wstring& path, bool sRgb = false, const sf::IntRect& area = {});
	~WTexture();

	bool LoadFromFile(const std::wstring& path, bool sRgb = false, const sf::IntRect& area = {});

	bool Resize(const sf::Vector2u& size)
	{
		if (mLoaded)
		{
			if (mTexture->resize(size))
				return true;
			else
				return true;
		}
		return false;
	}

public:
	std::shared_ptr<sf::Texture> GetTexture() { return mTexture; }
	sf::Texture& GetNativeTexture() { return *mTexture; }

	void SetSmooth(bool smooth) { mTexture->setSmooth(smooth); }
	bool IsSmooth() const { return mTexture->isSmooth(); }

	void SetRepeated(bool repeated) { mTexture->setRepeated(repeated); }
	bool IsRepeated() const { return mTexture->isRepeated(); }

	sf::Vector2u GetSize() const { return mTexture->getSize(); }

private:
	std::wstring mBasePath = L"../Asset/Texture/";

private:
	std::wstring mPath;
	std::shared_ptr<sf::Texture> mTexture;

	//flags
	bool mLoaded = false;
};

