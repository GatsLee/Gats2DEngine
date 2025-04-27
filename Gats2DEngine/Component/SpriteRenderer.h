#pragma once
#include "Component.h"
class SpriteRenderer : public Component
{
public:
	SpriteRenderer(std::shared_ptr<sf::Sprite> sprite, int32 order = 0);
	~SpriteRenderer();

	bool LoadFromFile(const std::wstring& textureName);

	void SetMaterial(std::shared_ptr<Material> material) { mMaterial = material; }
	void SetOrderIndex(int32 order) { mOrderIndex = order; }
	void SetOrigin(const sf::Vector2f& origin) { mSprite->setOrigin(origin); }
	void SetOriginCenter() { mSprite->setOrigin(sf::Vector2f(mSprite->getLocalBounds().size.x / 2.f, mSprite->getLocalBounds().size.y / 2.f)); }
	void SetColor(const sf::Color& color) { mSprite->setColor(color); }


	std::shared_ptr<sf::Sprite> GetSprite() { return mSprite; }
	sf::Vector2f GetOrigin() { return mSprite->getOrigin(); }
	sf::Color	GetColor() { return mSprite->getColor(); }

	void Update() override;
	void Render() override;

private:
	std::shared_ptr<sf::Sprite> mSprite;
	std::shared_ptr<Material> mMaterial;
	int32 mOrderIndex;
};

