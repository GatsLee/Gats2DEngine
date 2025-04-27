#pragma once
#include "UIWidget.h"
#include "Resource/WTexture.h"
#include "Resource/WFont.h"

class Sprite;
class WTexture;

class UILabel :
    public UIWidget
{
public:
	UILabel();
	UILabel(const std::wstring& fontName, const std::string& text, int fontSize = 30, const sf::Vector2f& position = {0.f, 0.f});
	~UILabel();

	void SetText(const sf::String& text) { mText->setString(text); }
	void SetPosition(const sf::Vector2f& position) { mText->setPosition(position); }
	void SetScale(float x, float y) { mText->setScale({ x, y }); }
	void SetFontSize(int fontSize) { mFontSize = fontSize; mText->setCharacterSize(fontSize); }
	void SetFont(std::shared_ptr<WFont> font) { mFont = font; }
	void SetColor(const sf::Color& color) { mColor = color; mText->setFillColor(color); }
	void SetOrigin(const sf::Vector2f& origin) { mText->setOrigin(origin); }
	void SetOriginCenter() { mText->setOrigin(sf::Vector2f(mText->getLocalBounds().size.x / 2.f, mText->getLocalBounds().size.y / 2.f)); }
	virtual void SetParentPanel(std::weak_ptr<UIPanel> parentPanel) override { mParentPanel = parentPanel; }

	void Update() override;
	void Render() override;


private:
	std::shared_ptr<sf::Text> mText;
	std::shared_ptr<WFont> mFont;
	int mFontSize;

	std::weak_ptr<UIPanel> mParentPanel;
};

