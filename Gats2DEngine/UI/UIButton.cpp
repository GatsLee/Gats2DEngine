#include "Headers/pch.h"
#include "UIButton.h"
#include "Resource/WFont.h"
#include "Resource/WTexture.h"

UIButton::UIButton(const std::wstring original, sf::Vector2f buttonPosition)
{
	mFont = RESOURCES->Get<WFont>(L"DefaultFont");
	mTextureResource = RESOURCES->Get<WTexture>(original);

	mOriginalSprite = std::make_shared<sf::Sprite>(mTextureResource->GetNativeTexture());
	mOriginalSprite->setPosition(buttonPosition);

	mText = std::make_shared<sf::Text>(mFont->GetNativeFont(), "HelloWorld", 30);
	// 110, 28 for 4 letters
	mText->setPosition({ buttonPosition.x + mTextOffset.x, buttonPosition.y + mTextOffset.y });
	mText->setFillColor(sf::Color::Black);

	mPosition = buttonPosition;
	mSize = { mOriginalSprite->getGlobalBounds().size.x, mOriginalSprite->getGlobalBounds().size.y };
}

UIButton::UIButton(std::wstring buttonSize, std::string text, sf::Vector2f buttonPosition, sf::Vector2f textOffset, int fontSize)
{
	mFont = RESOURCES->Get<WFont>(L"Joystix");
	mTextureResource = RESOURCES->Get<WTexture>(buttonSize);

	mOriginalSprite = std::make_shared<sf::Sprite>(mTextureResource->GetNativeTexture());;
	mOriginalSprite->setPosition(buttonPosition);
	
	mText = std::make_shared<sf::Text>(mFont->GetNativeFont(), text, fontSize);
	// 110, 28 for 4 letters
	mText->setPosition({ buttonPosition.x + textOffset.x, buttonPosition.y + textOffset.y });
	mText->setCharacterSize(fontSize);
	mText->setFillColor(sf::Color::Black);
	mTextOffset = textOffset;

	mPosition = buttonPosition;
	mSize = { mOriginalSprite->getGlobalBounds().size.x, mOriginalSprite->getGlobalBounds().size.y };
}

UIButton::~UIButton()
{
}

void UIButton::SetText(const sf::String& text)
{
	mText->setString(text);
}

void UIButton::SetPosition(float x, float y)
{
	sf::Vector2f pos = { x, y };
	mOriginalSprite->setPosition(pos);

	sf::FloatRect bounds = mOriginalSprite->getGlobalBounds();
	mText->setPosition(sf::Vector2f(bounds.position.x + mTextOffset.x, bounds.position.y + mTextOffset.y));

	mPosition = mOriginalSprite->getGlobalBounds().position;
	mSize = mOriginalSprite->getGlobalBounds().size;
}

void UIButton::SetScale(float x, float y)
{
	mOriginalSprite->setScale(sf::Vector2f{ x, y });
	mText->setCharacterSize(static_cast<unsigned int>(mText->getCharacterSize() * x));
}

void UIButton::SetColor(const sf::Color& color)
{
	sf::Color basedColor = color;
	sf::Color hoverColor = sf::Color(color.r / 2, color.g / 2, color.b / 2);
	sf::Color clickColor = sf::Color(color.r * 1.5, color.g * 1.5, color.b * 1.5);

	mOriginalSprite->setColor(color);
}
void UIButton::SetOrigin(const sf::Vector2f& origin, const sf::Vector2f& textOffset)
{
	mOriginalSprite->setOrigin(origin);

	sf::FloatRect bounds = mOriginalSprite->getGlobalBounds();
	mText->setPosition(sf::Vector2f(bounds.position.x + textOffset.x, bounds.position.y + textOffset.y));
}
void UIButton::SetOriginCenter(const sf::Vector2f& textPos)
{
	sf::FloatRect bounds = mOriginalSprite->getLocalBounds();
	mOriginalSprite->setOrigin(sf::Vector2f(mOriginalSprite->getLocalBounds().size.x / 2, mOriginalSprite->getLocalBounds().size.y / 2));
	
	bounds = mOriginalSprite->getGlobalBounds();
	mText->setPosition(sf::Vector2f(bounds.position.x + textPos.x, bounds.position.y + textPos.y));
	mTextOffset = textPos;
}

void UIButton::SetClickCallback(std::function<void()> callback)
{ 
	mClickCallback = callback;
}

void UIButton::Update()
{
	if (!mVisible)
		return;
	if (IsHovered())
	{
		if (IsClicked())
		{
			mOriginalSprite->setColor(mClickColor);

			if (mClickCallback)
			{
				mClickCallback();
			}
		}
		else
		{
			mOriginalSprite->setColor(mHoverColor);
		}
	}
	else
	{
		mOriginalSprite->setColor(sf::Color::White);
	}
}

void UIButton::Render()
{
	if (!mVisible)
		return;
	WINDOW->draw(*mOriginalSprite.get());
	WINDOW->draw(*mText);
}