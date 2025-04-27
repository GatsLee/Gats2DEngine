#pragma once
#include "EngineCore/Scene.h"

class TitleScene : public Scene
{
public:
	TitleScene();
	~TitleScene();

public:
	virtual void Initialize();
	virtual void Update();
	virtual void Render();

	virtual void OnEnter();
	virtual void OnExit();

private:
	// GameObjects
	// background
	// icon
	// UI
	// label(made by GatsLee)
};

