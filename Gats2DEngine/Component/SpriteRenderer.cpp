#include "Headers\pch.h"
#include "SpriteRenderer.h"
#include "Resource/Material.h"
#include "Resource/WTexture.h"

SpriteRenderer::SpriteRenderer(std::shared_ptr<sf::Sprite> sprite, int32 order)
	: Component(ComponentType::SpriteRenderer)
	, mSprite(sprite)
	, mOrderIndex(order)
{
	if (mSprite == nullptr)
	{
		sprite = std::make_shared<sf::Sprite>(RESOURCES->Get<WTexture>(L"DefaultTexture")->GetNativeTexture());
	}
}
SpriteRenderer::~SpriteRenderer()
{
}

bool SpriteRenderer::LoadFromFile(const std::wstring& textureName)
{
	// Load the texture from file
	std::shared_ptr<WTexture> texture = RESOURCES->Get<WTexture>(textureName);
	if (texture == nullptr)
	{
		DEBUG_PRINT_A1("SpriteRenderer::LoadFromFile | Texture not found: %s", textureName.c_str());
		return false;
	}
	// Create the sprite
	mSprite = std::make_shared<sf::Sprite>(texture->GetNativeTexture());
	if (mSprite == nullptr)
	{
		DEBUG_PRINT_A0("SpriteRenderer::LoadFromFile | Failed to create sprite from texture");
		return false;
	}

	return true;
}

void SpriteRenderer::Update()
{
	if (mSprite == nullptr)
	{
		return;
	}
	// Set the material
	if (mMaterial)
	{
		mMaterial->Apply(mSprite);
	}
	// Set the transform
	std::shared_ptr<Transform2D> transform = GetGameObject()->GetTransform2D();
	if (transform)
	{
		mSprite->setPosition(transform->GetWorldPosition());
		mSprite->setRotation(sf::degrees(transform->GetWorldRotation()));
		mSprite->setScale(transform->GetWorldScale());
	}
	else
	{
		transform = GetGameObject()->GetOrAddTransform2D();
	}
}

void SpriteRenderer::Render()
{
	if (mSprite == nullptr)
	{
		DEBUG_PRINT_A0("SpriteRenderer::Render | Sprite is null");
		return;
	}
	// Draw the sprite
	WINDOW->draw(*mSprite);
}
