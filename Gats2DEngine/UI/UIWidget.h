#pragma once

class UIPanel;

class UIWidget
{
public:
	UIWidget() = default;
	virtual ~UIWidget() = default;

	virtual void Update() = 0;
	virtual void Render() = 0;

	virtual void SetPosition(float x, float y) { mPosition = { x, y }; }
	virtual void SetSize(float width, float height) { mSize = { width, height }; }
	virtual void SetColor(const sf::Color& color) { mColor = color; }
	virtual void SetID(const std::string& id) { mID = id; }

	virtual sf::Vector2f GetPosition() const { return mPosition; }
	virtual sf::Vector2f GetSize() const { return mSize; }
	virtual sf::Color GetColor() const { return mColor; }
	virtual std::string GetID() const { return mID; }

	virtual void SetVisible(bool visible) { mVisible = visible; }
	virtual bool IsVisible() const { return mVisible; }

	virtual bool IsHovered() const
	{
		if (!mVisible)
			return false;

		sf::Vector2i mousePos = sf::Mouse::getPosition(*WINDOW);
		sf::Vector2f worldPos = WINDOW->mapPixelToCoords(mousePos);
		sf::FloatRect bounds = { {mPosition.x, mPosition.y}, {mSize.x, mSize.y} };

		return bounds.contains(worldPos);
	}
	virtual bool IsClicked() const
	{
		if (!mVisible)
			return false;
		if (UI->IsInputConsumed() && IsHovered())
		{
			return true;
		}
		return false;
	}

	virtual void SetParentPanel(std::weak_ptr<UIPanel> parent) {}

protected:
	sf::Vector2f mPosition;
	sf::Vector2f mSize;
	sf::Color mColor = sf::Color::White;
	std::string mID;

	//flags
	bool mVisible = true;
};

