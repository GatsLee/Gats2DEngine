#include "Headers/pch.h"
#include "UIPanel.h"

UIPanel::UIPanel(const sf::Vector2f& position, const sf::Vector2f& size)
	: UIWidget()
{
	mPosition = position;
	mSize = size;
	mBackground.setPosition(position);
	mBackground.setSize(size);
}

UIPanel::~UIPanel()
{
}

void UIPanel::SetColor(const sf::Color& color)
{
	mBackground.setFillColor(color);
	for (auto& child : mChildren)
	{
		child.second->SetColor(color);
	}
}

void UIPanel::SetDraggable(bool draggable)
{
	mDraggable = draggable;
	if (mDraggable)
	{
		mBackground.setOutlineThickness(2.f);
		mBackground.setOutlineColor(sf::Color::Black);
	}
	else
	{
		mBackground.setOutlineThickness(0.f);
	}
}

void UIPanel::SetVisible(bool visible)
{
	mVisible = visible;
	for (auto& child : mChildren)
	{
		child.second->SetVisible(visible);
	}
}

void UIPanel::RemoveChild(const std::wstring& name)
{
	auto iter = mChildren.find(name);
	if (iter != mChildren.end())
	{
		mChildren.erase(iter);
	}
	else
	{
		DEBUG_PRINT_W1(L"Child with name %s does not exist", name.c_str());
	}
}

void UIPanel::ClearChildren()
{
	mChildren.clear();
}

void UIPanel::Update()
{
	if (!mVisible)
		return;
	if (mDraggable && mDragging)
	{
		sf::Vector2i mousePos = sf::Mouse::getPosition(*WINDOW);
		mPosition.x = mousePos.x - mDragOffset.x;
		mPosition.y = mousePos.y - mDragOffset.y;
		mBackground.setPosition(mPosition);
	}
	for (auto& child : mChildren)
	{
		child.second->Update();
	}
}

void UIPanel::Render()
{
	if (!mVisible)
		return;
	for (auto& child : mChildren)
	{
		child.second->Render();
	}
}
