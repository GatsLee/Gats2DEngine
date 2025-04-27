#pragma once
#include "UIWidget.h"
class UIImage : public UIWidget
{
public:
	UIImage();
	UIImage(const std::wstring& textureName, const sf::Vector2f& position = {0.f, 0.f}, const sf::Vector2f& size = {0.f, 0.f});
	~UIImage();

	virtual void Update() override;
	virtual void Render() override;

	void SetTexture(const std::wstring& textureName);
	void SetPosition(const sf::Vector2f& position) { mSprite->setPosition(position); }
	void SetScale(float x, float y) { mSprite->setScale({ x, y }); }
	void SetColor(const sf::Color& color) { mSprite->setColor(color); }
	void SetOrigin(const sf::Vector2f& origin) { mSprite->setOrigin(origin); }
	void SetOriginCenter() { mSprite->setOrigin(sf::Vector2f(mSprite->getLocalBounds().size.x / 2.f, mSprite->getLocalBounds().size.y / 2.f)); }
	void SetSize(const sf::Vector2f& size) { mSprite->setScale(size); }
	virtual void SetParentPanel(std::weak_ptr<UIPanel> parentPanel) override { mParentPanel = parentPanel; }

private:
	std::shared_ptr<sf::Sprite> mSprite;
	std::weak_ptr<UIPanel> mParentPanel;
};

