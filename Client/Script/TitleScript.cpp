#include "stdafx.h"
#include "TitleScript.h"

void TitleScript::Awake()
{
}

void TitleScript::Start()
{
}

void TitleScript::Update()
{
	auto transform = GetOwner()->GetTransform2D();

	// Move in LOCAL space
	sf::Vector2f pos = transform->GetLocalPosition();
	pos.x += 30.f * DT; // 100 pixels per second
	transform->SetLocalPosition(pos);
}

void TitleScript::FixedUpdate()
{
}

void TitleScript::LateUpdate()
{
}

void TitleScript::OnDestroy()
{
}
