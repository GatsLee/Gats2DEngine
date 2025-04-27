#pragma once
#include "EngineCore\Scene.h"

class MenuScene : public Scene
{
public:
	MenuScene();
	~MenuScene();

	virtual void Initialize();
	virtual void Update();
	virtual void Render();

	virtual void OnEnter();
	virtual void OnExit();
private:
	void CreateMenuUI();

private:
};