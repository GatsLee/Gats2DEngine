#include "stdafx.h"
#include "GameScene.h"

GameScene::GameScene() : Scene("GameScene")
{
}

GameScene::~GameScene()
{
}

void GameScene::Initialize()
{
	DefaultInitialize();
	// GameObject Initialize
	{
		std::shared_ptr<GameObject> titleBackground = std::make_shared<GameObject>(L"TitleBackground");
		titleBackground->AddComponent(std::make_shared<SpriteRenderer>(std::make_shared<sf::Sprite>(RESOURCES->Get<WTexture>(L"TitleBackground")->GetNativeTexture())));
		titleBackground->GetOrAddTransform2D();
		titleBackground->GetOrAddTransform2D()->SetLocalPosition(sf::Vector2f(-300.f, 0.f));
		AddGameObject(L"TitleBackground", titleBackground);
	}

}
void GameScene::Update()
{
	DefaultUpdate();
}

void GameScene::Render()
{
	DefaultRender(); 
}

void GameScene::OnEnter()
{
	Initialize();
}

void GameScene::OnExit()
{
}
