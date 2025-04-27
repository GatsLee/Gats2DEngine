#include "Headers/pch.h"
#include "ScriptComponent.h"

ScriptComponent::ScriptComponent() : Component(ComponentType::ScriptComponent)
{
}

ScriptComponent::~ScriptComponent()
{
}

void ScriptComponent::Start()
{
	for (const auto& script : mScripts)
	{
		script->Start();
	}
}

void ScriptComponent::Awake()
{
	for (const auto& script : mScripts)
	{
		script->Awake();
	}
}

void ScriptComponent::Update()
{
	for (const auto& script : mScripts)
	{
		script->Update();
	}
}

void ScriptComponent::FixedUpdate()
{
	for (const auto& script : mScripts)
	{
		script->FixedUpdate();
	}
}

void ScriptComponent::LateUpdate()
{
	for (const auto& script : mScripts)
	{
		script->LateUpdate();
	}
}

void ScriptComponent::OnDestroy()
{
	for (const auto& script : mScripts)
	{
		script->OnDestroy();
	}
}
