#include "stdafx.h"
#include "TitleScene.h"
#include "MenuScene.h"

MenuScene::MenuScene() : Scene("MenuScene")
{
}

MenuScene::~MenuScene()
{
}

void MenuScene::Initialize()
{
	// MENU part
	{
		std::shared_ptr<GameObject> titleBackground = std::make_shared<GameObject>(L"TitleBackground");
		titleBackground->AddComponent(std::make_shared<SpriteRenderer>(std::make_shared<sf::Sprite>(RESOURCES->Get<WTexture>(L"TitleBackground")->GetNativeTexture())));
		titleBackground->GetOrAddTransform2D();
		titleBackground->GetOrAddTransform2D()->SetLocalPosition(sf::Vector2f(-300.f, 0.f));

		AddGameObject(L"GameBackground", titleBackground);

		CreateMenuUI();
	}
	// Game Part
	{

	}
	DefaultInitialize();
}

void MenuScene::Update()
{
	DefaultUpdate();
}

void MenuScene::Render()
{
	DefaultRender();
}

void MenuScene::OnEnter()
{
	Initialize();
}

void MenuScene::OnExit()
{
}

void MenuScene::CreateMenuUI()
{
	// start exit
	std::shared_ptr<UIPanel> startExitPanel = std::make_shared<UIPanel>(sf::Vector2f(0.f, 0.f), sf::Vector2f(300.f, 400.f));
	AddUIWidget(L"2_StartExitPanel", startExitPanel);
	startExitPanel->AddChild(L"0_ModalBackground", std::make_shared<UIImage>(L"ModalBackgroundBig"));
	startExitPanel->AddChild(L"1_GomokuTitle", std::make_shared<UIImage>(L"TitleText"));
	startExitPanel->AddChild(L"2_MadeText", std::make_shared<UILabel>(L"Joystix", "Made by GatsLee", 30, sf::Vector2f(300.f, 400.f)));
	startExitPanel->AddChild(L"2_StartButton", std::make_shared<UIButton>(L"GomokuButtonBig", "Start", sf::Vector2f(300.f, 600.f), sf::Vector2f(100.f, 25.f), 35) );
	startExitPanel->AddChild(L"2_ExitButton", std::make_shared<UIButton>(L"GomokuButtonBig", "Exit", sf::Vector2f(300.f, 500.f), sf::Vector2f(110.f, 25.f), 35) );


	auto modalBackground = startExitPanel->GetChild<UIImage>(L"0_ModalBackground");
	auto gomokuTitle = startExitPanel->GetChild<UIImage>(L"1_GomokuTitle");
	modalBackground->SetOriginCenter();
	modalBackground->SetPosition(sf::Vector2f(500.f, 500.f));
	modalBackground->SetScale(1.f, 1.f);
	gomokuTitle->SetOriginCenter();
	gomokuTitle->SetPosition(sf::Vector2f(500.f, 280.f));
	gomokuTitle->SetScale(0.65f, 0.65f);

	auto madeText = startExitPanel->GetChild<UILabel>(L"2_MadeText");
	madeText->SetOriginCenter();
	madeText->SetPosition(sf::Vector2f(500.f, 350.f));

	auto startButton = startExitPanel->GetChild<UIButton>(L"2_StartButton");
	auto exitButton = startExitPanel->GetChild<UIButton>(L"2_ExitButton");
	startButton->SetOriginCenter(sf::Vector2f(90.f, 22.f));
	startButton->SetPosition(500.f, 500.f);
	// set callback: select play mode panel visible
	exitButton->SetOriginCenter(sf::Vector2f(95.f, 22.f));
	exitButton->SetPosition(500.f, 650.f);
	exitButton->SetClickCallback([]() {
		// exit game
		WINDOW->close();
		});
	// set callback: exit game(stop application)
	modalBackground->SetParentPanel(startExitPanel);
	gomokuTitle->SetParentPanel(startExitPanel);
	madeText->SetParentPanel(startExitPanel);
	startButton->SetParentPanel(startExitPanel);
	exitButton->SetParentPanel(startExitPanel);
	
	startExitPanel->SetVisible(true);
	// local play or AI play
	std::shared_ptr<UIPanel> selectPlayPanel = std::make_shared<UIPanel>(sf::Vector2f(0.f, 0.f), sf::Vector2f(300.f, 400.f));
	AddUIWidget(L"1_SelectPlayPanel", selectPlayPanel);
	selectPlayPanel->AddChild(L"0_ModalBackground", std::make_shared<UIImage>(L"ModalBackgroundBig"));
	selectPlayPanel->AddChild(L"1_SelectTitle", std::make_shared<UIImage>(L"SelectText"));
	selectPlayPanel->AddChild(L"2_LocalPlayButton", std::make_shared<UIButton>(L"GomokuButtonBig", "Local Play", sf::Vector2f(300.f, 600.f), sf::Vector2f(100.f, 25.f), 35));
	selectPlayPanel->AddChild(L"2_AIPlayButton", std::make_shared<UIButton>(L"GomokuButtonBig", "AI Play", sf::Vector2f(300.f, 500.f), sf::Vector2f(110.f, 25.f), 35));
	selectPlayPanel->AddChild(L"2_BackButton", std::make_shared<UIButton>(L"GomokuButtonBig", "Back", sf::Vector2f(300.f, 400.f), sf::Vector2f(110.f, 25.f), 35));

	auto modalBackground2 = selectPlayPanel->GetChild<UIImage>(L"0_ModalBackground");
	auto selectTitle = selectPlayPanel->GetChild<UIImage>(L"1_SelectTitle");
	modalBackground2->SetOriginCenter();
	modalBackground2->SetPosition(sf::Vector2f(500.f, 500.f));
	modalBackground2->SetScale(1.f, 1.f);
	selectTitle->SetOriginCenter();
	selectTitle->SetPosition(sf::Vector2f(500.f, 280.f));
	selectTitle->SetScale(0.9f, 0.9f);


	auto localPlayButton = selectPlayPanel->GetChild<UIButton>(L"2_LocalPlayButton");
	auto aiPlayButton = selectPlayPanel->GetChild<UIButton>(L"2_AIPlayButton");
	auto backButton = selectPlayPanel->GetChild<UIButton>(L"2_BackButton");
	localPlayButton->SetOriginCenter(sf::Vector2f(13.f, 22.f));
	localPlayButton->SetPosition(500.f, 400.f);
	aiPlayButton->SetOriginCenter(sf::Vector2f(60.f, 22.f));
	aiPlayButton->SetPosition(500.f, 550.f);
	backButton->SetOriginCenter(sf::Vector2f(95.f, 22.f));
	backButton->SetPosition(500.f, 700.f);

	modalBackground2->SetParentPanel(selectPlayPanel);
	selectTitle->SetParentPanel(selectPlayPanel);
	localPlayButton->SetParentPanel(selectPlayPanel);
	aiPlayButton->SetParentPanel(selectPlayPanel);
	backButton->SetParentPanel(selectPlayPanel);

	selectPlayPanel->SetVisible(false);

	// stone select
	std::shared_ptr<UIPanel> selectStonePanel = std::make_shared<UIPanel>(sf::Vector2f(0.f, 0.f), sf::Vector2f(300.f, 400.f));
	AddUIWidget(L"SelectStonePanel", selectStonePanel);
	selectStonePanel->AddChild(L"0_ModalBackground", std::make_shared<UIImage>(L"ModalBackgroundBig"));
	selectStonePanel->AddChild(L"1_SelectTitle", std::make_shared<UIImage>(L"SelectText"));
	selectStonePanel->AddChild(L"2_BlackStoneImage", std::make_shared<UIImage>(L"WhiteStone"));
	selectStonePanel->AddChild(L"2_WhiteStoneImage", std::make_shared<UIImage>(L"BlackStone"));
	selectStonePanel->AddChild(L"2_WhiteButton", std::make_shared<UIButton>(L"GomokuButtonBig", "White", sf::Vector2f(300.f, 600.f), sf::Vector2f(100.f, 25.f), 35));
	selectStonePanel->AddChild(L"2_BlackButton", std::make_shared<UIButton>(L"GomokuButtonBig", "Black", sf::Vector2f(300.f, 500.f), sf::Vector2f(110.f, 25.f), 35));
	selectStonePanel->AddChild(L"3_BackButton", std::make_shared<UIButton>(L"GomokuButtonBig", "Back", sf::Vector2f(300.f, 400.f), sf::Vector2f(110.f, 25.f), 35));


	auto modalBackground3 = selectStonePanel->GetChild<UIImage>(L"0_ModalBackground");
	auto selectTitle2 = selectStonePanel->GetChild<UIImage>(L"1_SelectTitle");
	modalBackground3->SetOriginCenter();
	modalBackground3->SetPosition(sf::Vector2f(500.f, 500.f));
	modalBackground3->SetScale(1.f, 1.f);
	selectTitle2->SetOriginCenter();
	selectTitle2->SetPosition(sf::Vector2f(500.f, 280.f));
	selectTitle2->SetScale(0.9f, 0.9f);

	auto blackStoneImage = selectStonePanel->GetChild<UIImage>(L"2_BlackStoneImage");
	auto whiteStoneImage = selectStonePanel->GetChild<UIImage>(L"2_WhiteStoneImage");
	auto whiteButton = selectStonePanel->GetChild<UIButton>(L"2_WhiteButton");
	auto blackButton = selectStonePanel->GetChild<UIButton>(L"2_BlackButton");
	auto backButton2 = selectStonePanel->GetChild<UIButton>(L"3_BackButton");
	blackStoneImage->SetOriginCenter();
	blackStoneImage->SetPosition(sf::Vector2f(300.f, 400.f));
	blackStoneImage->SetScale(0.8f, 0.8f);
	whiteStoneImage->SetOriginCenter();
	whiteStoneImage->SetPosition(sf::Vector2f(300.f, 550.f));
	whiteStoneImage->SetScale(0.8f, 0.8f);

	whiteButton->SetOriginCenter(sf::Vector2f(90.f, 22.f));
	whiteButton->SetPosition(500.f, 400.f);
	blackButton->SetOriginCenter(sf::Vector2f(90.f, 22.f));
	blackButton->SetPosition(500.f, 550.f);
	backButton2->SetOriginCenter(sf::Vector2f(95.f, 22.f));
	backButton2->SetPosition(500.f, 700.f);
	
	modalBackground3->SetParentPanel(selectStonePanel);
	selectTitle2->SetParentPanel(selectStonePanel);
	blackStoneImage->SetParentPanel(selectStonePanel);
	whiteStoneImage->SetParentPanel(selectStonePanel);
	whiteButton->SetParentPanel(selectStonePanel);
	blackButton->SetParentPanel(selectStonePanel);
	backButton2->SetParentPanel(selectStonePanel);

	selectStonePanel->SetVisible(false);
	// set callback: select play mode panel visible
	//// start exit
	startButton->SetClickCallback([startButton, selectPlayPanel]() {
		if (startButton->GetParentPanel().lock())
		{
			startButton->GetParentPanel().lock()->SetVisible(false);
		}

		UI->LockUI(0.1f);

		COROUTINE->StartCoroutine(0.1f, [selectPlayPanel]() {
			selectPlayPanel->SetVisible(true);
			});
		});
	//// play mode selection
	localPlayButton->SetClickCallback([localPlayButton, selectStonePanel]() {
		if (localPlayButton->GetParentPanel().lock())
		{
			localPlayButton->GetParentPanel().lock()->SetVisible(false);
		}

		UI->LockUI(0.1f);

		COROUTINE->StartCoroutine(0.1f, [selectStonePanel]() {
			selectStonePanel->SetVisible(true);
			});

		});
	aiPlayButton->SetClickCallback([aiPlayButton]() {
		if (aiPlayButton->GetParentPanel().lock())
		{
			aiPlayButton->GetParentPanel().lock()->SetVisible(false);
		}
		});
	//// stone selection
	whiteButton->SetClickCallback([whiteButton]() {
		if (whiteButton->GetParentPanel().lock())
		{
			whiteButton->GetParentPanel().lock()->SetVisible(false);
		}

		UI->LockUI(0.1f);


		COROUTINE->StartCoroutine(0.1f, []() {
			// start game scene
			SCENE->ChangeScene(L"MenuScene");
			});



		});
	blackButton->SetClickCallback([blackButton]() {
		if (blackButton->GetParentPanel().lock())
		{
			blackButton->GetParentPanel().lock()->SetVisible(false);
		}
		});
}
