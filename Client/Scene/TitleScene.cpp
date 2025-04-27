#include "stdafx.h"
#include "TitleScene.h"
#include "Script/TitleScript.h"

TitleScene::TitleScene() : Scene("TitleScene")
{
}

TitleScene::~TitleScene()
{
}

void TitleScene::Initialize()
{
	DefaultInitialize();
	// GameObject Initialize
	{
		std::shared_ptr<GameObject> titleBackground = std::make_shared<GameObject>(L"TitleBackground");
		titleBackground->AddComponent(std::make_shared<SpriteRenderer>(std::make_shared<sf::Sprite>(RESOURCES->Get<WTexture>(L"TitleBackground")->GetNativeTexture())));
		titleBackground->GetOrAddTransform2D();
		titleBackground->GetOrAddTransform2D()->SetLocalPosition(sf::Vector2f(-300.f, 0.f));
		std::shared_ptr<TitleScript> script = titleBackground->AddScript<TitleScript>("TitleBackgroundScript");

		AddGameObject(L"TitleBackground", titleBackground);
	}
	// UI Initialize
	{
		std::shared_ptr<UILabel> titleText = std::make_shared<UILabel>(L"Joystix", "Made by\nGats Lee", 60, sf::Vector2f(300,500));
		titleText->SetColor(sf::Color::Black);
		titleText->SetOriginCenter();
		titleText->SetPosition(sf::Vector2f(420, 490));
		AddUIWidget(L"TitleText", titleText);
	}
	{
		std::shared_ptr<UIImage> gatsIcon = std::make_shared<UIImage>(L"GatsIcon");
		gatsIcon->SetOriginCenter();
		gatsIcon->SetPosition(sf::Vector2f(700, 500));
		gatsIcon->SetScale(0.7f, 0.7f);
		AddUIWidget(L"GatsIcon", gatsIcon);
	}
}
void TitleScene::Update()
{
	DefaultUpdate();
}

void TitleScene::Render()
{
	DefaultRender(); 
}

void TitleScene::OnEnter()
{
	Initialize();
	COROUTINE->StartCoroutine(2.5f, [this]() {
		SCENE->ChangeScene("GameScene");
		});
}

void TitleScene::OnExit()
{
}
