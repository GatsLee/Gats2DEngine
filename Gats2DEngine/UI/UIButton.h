#pragma once
#include "UIWidget.h"
#include "UIPanel.h"


class WTexture;

class UIButton : public UIWidget
{
public:
	// Specific constructor for Gomoku
	UIButton(std::wstring buttonSize, std::string text, \
		sf::Vector2f buttonPosition, sf::Vector2f textOffset, int fontSize = 30);
	UIButton(const std::wstring original, sf::Vector2f buttonPosition);
	~UIButton();

	void SetText(const sf::String& text);
	void SetPosition(float x, float y);
	void SetScale(float x, float y);
	void SetColor(const sf::Color& color);
	void SetOrigin(const sf::Vector2f& origin, const sf::Vector2f& textOffset);
	void SetOriginCenter(const sf::Vector2f& textOffset);
	void SetClickCallback(std::function<void()> callback);
	virtual void SetParentPanel(std::weak_ptr<UIPanel> parentPanel) override { mParentPanel = parentPanel; }

	void Update() override;
	void Render() override;

	std::weak_ptr<UIPanel> GetParentPanel() const { return mParentPanel; }

private:
	std::shared_ptr<WFont> mFont;
	std::shared_ptr<WTexture> mTextureResource;
	std::shared_ptr<sf::Sprite> mOriginalSprite;

	sf::Color 	mHoverColor = sf::Color(128, 128, 128);
	sf::Color 	mClickColor = sf::Color(150, 150, 150);

	std::shared_ptr<sf::Text> mText;
	sf::Vector2f mTextOffset = { 0.f, 0.f };
	int mFontSize;

	std::function<void()> mClickCallback = nullptr;
	std::weak_ptr<UIPanel> mParentPanel;
};

