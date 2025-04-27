#include "Headers/pch.h"
#include "GameObject.h"
#include "Component/ScriptComponent.h"
#include "Component/Transform2D.h"
#include "Component/Camera.h"
#include "Component/SpriteRenderer.h"
#include "Component/Animator.h"

std::shared_ptr<Component> GameObject::GetFixedComponent(ComponentType type)
{
	uint8 index = static_cast<uint8>(type);
	assert(index < FIXED_COMPONENT_COUNT);
	return mComponents[index];
}

std::shared_ptr<Transform2D> GameObject::GetTransform2D()
{
	std::shared_ptr<Component> component = GetFixedComponent(ComponentType::Transform2D);
	return std::static_pointer_cast<Transform2D>(component);
}

std::shared_ptr<SpriteRenderer> GameObject::GetSpriteRenderer()
{
	std::shared_ptr<Component> component = GetFixedComponent(ComponentType::SpriteRenderer);
	return std::static_pointer_cast<SpriteRenderer>(component);
}

std::shared_ptr<Animator> GameObject::GetAnimator()
{
	std::shared_ptr<Component> component = GetFixedComponent(ComponentType::Animator);
	return std::static_pointer_cast<Animator>(component);
}

std::shared_ptr<Camera> GameObject::GetCamera()
{
	std::shared_ptr<Component> component = GetFixedComponent(ComponentType::Camera);
	return std::static_pointer_cast<Camera>(component);
}

std::shared_ptr<ScriptComponent> GameObject::GetScriptComponent()
{
	std::shared_ptr<Component> component = GetFixedComponent(ComponentType::ScriptComponent);
	return std::static_pointer_cast<ScriptComponent>(component);
}

std::shared_ptr<Transform2D> GameObject::GetOrAddTransform2D()
{
	if (GetTransform2D() == nullptr)
	{
		std::shared_ptr<Transform2D> transform = std::make_shared<Transform2D>();
		AddComponent(transform);
	}
	return GetTransform2D();
}

void GameObject::Awake()
{
	for (std::shared_ptr<Component>& component : mComponents)
	{
		if (component)
			component->Awake();
	}

	for (std::shared_ptr<ScriptComponent>& script : mScripts)
	{
		script->Awake();
	}
}

void GameObject::Start()
{
	for (std::shared_ptr<Component>& component : mComponents)
	{
		if (component)
			component->Start();
	}

	for (std::shared_ptr<ScriptComponent>& script : mScripts)
	{
		script->Start();
	}
}

void GameObject::Update()
{
	for (std::shared_ptr<Component>& component : mComponents)
	{
		if (component)
			component->Update();
	}

	for (std::shared_ptr<ScriptComponent>& script : mScripts)
	{
		script->Update();
	}
}

void GameObject::FixedUpdate()
{
	for (std::shared_ptr<Component>& component : mComponents)
	{
		if (component)
			component->FixedUpdate();
	}

	for (std::shared_ptr<ScriptComponent>& script : mScripts)
	{
		script->FixedUpdate();
	}
}

void GameObject::LateUpdate()
{
	for (std::shared_ptr<Component>& component : mComponents)
	{
		if (component)
			component->LateUpdate();
	}

	for (std::shared_ptr<ScriptComponent>& script : mScripts)
	{
		script->LateUpdate();
	}
}

void GameObject::Render()
{
	for (std::shared_ptr<Component>& component : mComponents)
	{
		if (component)
			component->Render();
	}
	for (std::shared_ptr<ScriptComponent>& script : mScripts)
	{
		script->Render();
	}
}

void GameObject::AddComponent(std::shared_ptr<Component> component)
{
	component->SetGameObject(shared_from_this());

	uint8 index = static_cast<uint8>(component->GetType());

	if (index <= FIXED_COMPONENT_COUNT)
	{
		mComponents[index] = component;
	}
	else
	{
		mScripts.push_back(std::dynamic_pointer_cast<ScriptComponent>(component));
	}
}