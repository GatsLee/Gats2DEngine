#include "Headers/pch.h"
#include "WFont.h"

WFont::WFont()
	:ResourceBase(ResourceType::WFont)
{
	mFont = std::make_shared<sf::Font>();
	if (!mFont->openFromFile(fontPath + L"DefaultFont.otf"))
	{
		mLoaded = false;
		CHECK(false, L"Font Load Failed");
	}
}

WFont::WFont(std::wstring fontName)
	:ResourceBase(ResourceType::WFont)
{
	mFont = std::make_shared<sf::Font>();
	if (!mFont->openFromFile(fontPath + fontName))
	{
		mLoaded = false;
		CHECK(false, L"Font Load Failed");
	}
}

WFont::~WFont()
{
}
