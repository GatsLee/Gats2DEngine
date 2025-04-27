#include "Headers\pch.h"
#include "UIImage.h"

UIImage::UIImage()
	: UIWidget()
{
	mSprite = std::make_shared<sf::Sprite>(RESOURCES->Get<WTexture>(L"DefaultTexture")->GetNativeTexture());
}

UIImage::UIImage(const std::wstring& textureName, const sf::Vector2f& position, const sf::Vector2f& size)
	: UIWidget()
{
	if (RESOURCES->Get<WTexture>(textureName) == nullptr)
	{
		ASSERT_MSG(false, "UIImage::UIImage | Texture not found");
	}
	mSprite = std::make_shared<sf::Sprite>(RESOURCES->Get<WTexture>(textureName)->GetNativeTexture());
	mPosition = position;
	mSize = size;
	mSprite->setPosition(position);
	mSprite->setScale(size);
}

UIImage::~UIImage()
{
}

void UIImage::Update()
{
	if (mSprite == nullptr || !mVisible)
	{
		return;
	}
}

void UIImage::Render()
{
	if (!mVisible)
		return;
	WINDOW->draw(*mSprite);
}

void UIImage::SetTexture(const std::wstring& textureName)
{
	// Load the texture from file
	if (RESOURCES->Get<WTexture>(textureName) == nullptr)
	{
		ASSERT_MSG(false, "UIImage::SetTexture | Texture not found");
	}
	mSprite = std::make_shared<sf::Sprite>(RESOURCES->Get<WTexture>(textureName)->GetNativeTexture());
}
