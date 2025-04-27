#pragma once
#include "ResourceBase.h"

class WFont : public ResourceBase
{
public:
	WFont();
	WFont(std::wstring fontName);
	~WFont();

public:
	std::shared_ptr<sf::Font> GetFont() { return mFont; }
	sf::Font& GetNativeFont() { return *mFont; }

public:
	std::wstring fontPath = L"../Asset/Font/";

private:
	std::shared_ptr<sf::Font> mFont;
};

