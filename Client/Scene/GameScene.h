#pragma once
#include "EngineCore/Scene.h"

class GameScene : public Scene
{
public:
	GameScene();
	~GameScene();

public:
	virtual void Initialize();
	virtual void Update();
	virtual void Render();

	virtual void OnEnter();
	virtual void OnExit();

private:
};

