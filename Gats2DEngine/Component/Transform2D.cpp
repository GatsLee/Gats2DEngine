#include "Headers/pch.h"
#include "Transform2D.h"

Transform2D::Transform2D()
	: Component(ComponentType::Transform2D)
{
	mLocalPosition = { 0.f, 0.f };
	mLocalRotation = 0.f;
	mLocalScale = { 1.f, 1.f };
	mDirty = true;
}

void Transform2D::SetLocalPosition(const sf::Vector2f& pos)
{
	mLocalPosition = pos;
	mDirty = true;
}

void Transform2D::SetLocalRotation(float angle)
{
	mLocalRotation = angle;
	mDirty = true;
}

void Transform2D::SetLocalScale(const sf::Vector2f& scale)
{
	mLocalScale = scale;
	mDirty = true;
}

void Transform2D::SetWorldPosition(const sf::Vector2f& pos)
{
	if (auto p = mParent.lock())
	{
		mLocalPosition = pos - p->GetWorldPosition();
	}
	else
	{
		mLocalPosition = pos;
	}
	mDirty = true;
}

void Transform2D::SetWorldRotation(float angle)
{
	if (auto p = mParent.lock())
	{
		float parentRotation = p->GetWorldRotation();
		mLocalRotation = angle - parentRotation;
	}
	else
	{
		mLocalRotation = angle;
	}

	mDirty = true;
}

void Transform2D::SetWorldScale(const sf::Vector2f& scale)
{
	if (auto p = mParent.lock())
	{
		sf::Vector2f parentScale = p->GetWorldScale();
		mLocalScale.x = scale.x / parentScale.x;
		mLocalScale.y = scale.y / parentScale.y;
	}
	else
	{
		mLocalScale = scale;
	}

	mDirty = true;
}

sf::Vector2f& Transform2D::GetLocalPosition()
{
	return mLocalPosition;
}

float& Transform2D::GetLocalRotation()
{
	return mLocalRotation;
}

sf::Vector2f& Transform2D::GetLocalScale()
{
	return mLocalScale;
}

sf::Vector2f& Transform2D::GetWorldPosition()
{
	sf::Vector2f position = mLocalPosition;
	if (auto p = mParent.lock())
	{
		position.x += p->GetWorldPosition().x;
		position.y += p->GetWorldPosition().y;
	}
	return position;
}

float& Transform2D::GetWorldRotation()
{
	float rotation = mLocalRotation;
	if (auto p = mParent.lock())
		rotation += p->GetWorldRotation();
	return rotation;
}

sf::Vector2f& Transform2D::GetWorldScale()
{
	sf::Vector2f scale = mLocalScale;
	if (auto p = mParent.lock())
	{
		scale.x *= p->GetWorldScale().x;
		scale.y *= p->GetWorldScale().y;
	}
	return scale;
}

sf::Transform& Transform2D::GetWorldMatrix()
{
	if (mDirty)
		UpdateTransform();
	return mCachedWorldTransform;
}

void Transform2D::SetParent(std::shared_ptr<Transform2D> parent)
{
	mParent = parent;
	mDirty = true;
}

std::shared_ptr<Transform2D> Transform2D::GetParent()
{
	return mParent.lock();
}

void Transform2D::AddChild(std::shared_ptr<Transform2D> child)
{
	if (child)
	{
		mChildren.push_back(child);
		child->SetParent(shared_from_this());
	}
	else
	{
		DEBUG_PRINT_A0("Transform2D::AddChild: child is null");
	}
}

std::vector<std::shared_ptr<Transform2D>>& Transform2D::GetChildren()
{
	return mChildren;
}

sf::Vector2f Transform2D::GetRight()
{
	float radian = (GetWorldRotation() * 3.14159265f) / 180.f;
	return sf::Vector2f(cos(radian), sin(radian));
}

sf::Vector2f Transform2D::GetUp()
{
	float radians = (GetWorldRotation() + 90.f) * 3.14159265f / 180.f;
	return { std::cos(radians), std::sin(radians) };
}

void Transform2D::UpdateTransform()
{
	sf::Transform local;
	local.translate(mLocalPosition);
	local.rotate(sf::degrees(mLocalRotation));
	local.scale(mLocalScale);


	if (auto p = mParent.lock())
		mCachedWorldTransform = p->GetWorldMatrix() * local;
	else
		mCachedWorldTransform = local;

	mDirty = false;
	for (auto& child : mChildren)
	{
		child->UpdateTransform();
	}
}
