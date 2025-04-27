#include "Headers/pch.h"
#include "Component.h"
#include "GameObject/GameObject.h"

Component::Component(ComponentType type)
	: mType(type)
{
}

Component::~Component()
{
}

void Component::Awake()
{
}

void Component::Start()
{
}

void Component::Update()
{
}

void Component::FixedUpdate()
{
}

void Component::LateUpdate()
{
}

void Component::Render()
{
}

void Component::OnDestroy()
{
}

std::shared_ptr<GameObject> Component::GetGameObject() { return mGameObject.lock(); }
std::shared_ptr<Transform2D> Component::GetTransform2D()
{
	std::shared_ptr<GameObject> gameObject = mGameObject.lock();
	if (gameObject)
	{
		return gameObject->GetTransform2D();
	}
	return nullptr;
}
//shared_ptr<Transform> Component::GetTransform() { return mGameObject.lock()->GetTransform(); }
