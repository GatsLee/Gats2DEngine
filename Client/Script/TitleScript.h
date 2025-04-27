#pragma once
#include "Component\ScriptComponent.h"

class TitleScript : public Script
{
public:
	TitleScript() = default;
	TitleScript(std::string name) : Script(name) {}
	~TitleScript() = default;

	virtual void Awake() override;
	virtual void Start() override;
	virtual void Update() override;
	virtual void FixedUpdate() override;
	virtual void LateUpdate() override;
	virtual void OnDestroy() override;

private:
};

