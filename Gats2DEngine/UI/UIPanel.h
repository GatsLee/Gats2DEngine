#pragma once
#include "UIWidget.h"
class UIPanel : public UIWidget, std::enable_shared_from_this<UIPanel>
{
public:
	UIPanel(const sf::Vector2f& position, const sf::Vector2f& size);
	~UIPanel();

	void SetColor(const sf::Color& color);
	void SetDraggable(bool draggable);
	virtual void SetVisible(bool visible) override;

	template<typename T>
	void AddChild(const std::wstring& name, std::shared_ptr<T> child)
	{
		static_assert(std::is_base_of<UIWidget, T>::value, "T must be derived from UIWidget");
		if (child)
		{
			mChildren[name] = child;
		}
		else
		{
			DEBUG_PRINT_A0("UIPanel::AddChild: child is null");
		}
	}
	template<typename T>
	std::shared_ptr<T> GetChild(const std::wstring& name)
	{
		static_assert(std::is_base_of<UIWidget, T>::value, "T must be derived from UIWidget");
		auto iter = mChildren.find(name);
		if (iter != mChildren.end())
		{
			return std::dynamic_pointer_cast<T>(iter->second);
		}
		else
		{
			DEBUG_PRINT_W1(L"Child with name %s does not exist", name.c_str());
			return nullptr;
		}
	}
	void FixChildParent()
	{
		for (auto& child : mChildren)
		{
			child.second->SetParentPanel(shared_from_this());
		}
	}
	void RemoveChild(const std::wstring& name); 
	void ClearChildren();

	virtual void Update() override;
	virtual void Render() override;


private:
	sf::RectangleShape mBackground;
	std::map<std::wstring, std::shared_ptr<UIWidget>> mChildren;

	bool mDraggable = false;
	bool mDragging = false;
	sf::Vector2f mDragOffset = { 0.f, 0.f };
};

