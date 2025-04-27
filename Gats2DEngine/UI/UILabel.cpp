#include "Headers/pch.h"
#include "UILabel.h"
#include "Resource/WFont.h"

UILabel::UILabel()
{
	mFont = RESOURCES->Get<WFont>(L"Default");
	mText = std::make_shared<sf::Text>(*mFont->GetFont(), L"Default", 20);
	mText->setFillColor(sf::Color::Black);

	mText->setPosition({ 0, 0 });
	mFontSize = 20;
	mText->setCharacterSize(mFontSize);
}

UILabel::UILabel(const std::wstring& fontName, const std::string& text, int fontSize, const sf::Vector2f& position)
{
	mFont = RESOURCES->Get<WFont>(fontName);

	mText = std::make_shared<sf::Text>(*mFont->GetFont(), text, fontSize);
	mText->setFillColor(sf::Color::Black);
	mText->setPosition(position);
	mFontSize = fontSize;
}

UILabel::~UILabel()
{
}

void UILabel::Update()
{
	if (!mVisible)
		return;
}

void UILabel::Render()
{
	if (!mVisible)
		return;
	WINDOW->draw(*mText);
}