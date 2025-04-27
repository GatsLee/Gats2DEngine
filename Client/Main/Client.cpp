// Client.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "stdafx.h"
#include "Scene/TitleScene.h"
#include "Scene/MenuScene.h"
#include "Scene/GameScene.h"

void CreateTitleScene()
{
	auto scene = std::make_shared<TitleScene>();
	SCENE->AddSceneToMap("TitleScene", scene);
	SCENE->PushScene("TitleScene");
}

void CreateMenuScene()
{
	auto scene = std::make_shared<MenuScene>();
	SCENE->AddSceneToMap("MenuScene", scene);
}

void CreateGameScene()
{
	auto scene = std::make_shared<GameScene>();
	SCENE->AddSceneToMap("GameScene", scene);
}

void ImportResources()
{
	RESOURCES->Add<WTexture>(L"TitleBackground", std::make_shared<WTexture>(L"Background_Sky.png"));
	RESOURCES->Add<WFont>(L"Joystix", std::make_shared<WFont>(L"joystix_monospace.otf"));
	RESOURCES->Add<WTexture>(L"GatsIcon", std::make_shared<WTexture>(L"icon.png"));

	// menu resources
	RESOURCES->Add<WTexture>(L"ModalBackgroundBig", std::make_shared<WTexture>(L"ModalBackgroundBig.png"));
	RESOURCES->Add<WTexture>(L"ModalBackgroundMedium", std::make_shared<WTexture>(L"ModalBackgroundMedium.png"));
	RESOURCES->Add<WTexture>(L"GomokuButtonBig", std::make_shared<WTexture>(L"GomokuButtonBig.png"));
	RESOURCES->Add<WTexture>(L"GomokuButtonMedium", std::make_shared<WTexture>(L"GomokuButtonMedium.png"));
	RESOURCES->Add<WTexture>(L"GomokuButtonSmall", std::make_shared<WTexture>(L"GomokuButtonSmall.png"));

	RESOURCES->Add<WTexture>(L"TitleText", std::make_shared<WTexture>(L"GomokuTitle.png"));
	RESOURCES->Add<WTexture>(L"SelectText", std::make_shared<WTexture>(L"SelectTitle.png"));
	RESOURCES->Add<WTexture>(L"PauseText", std::make_shared<WTexture>(L"PauseTitle.png"));
	RESOURCES->Add<WTexture>(L"GameOverText", std::make_shared<WTexture>(L"GameOverTitle.png"));


	// game resources
	RESOURCES->Add<WTexture>(L"GoBoard", std::make_shared<WTexture>(L"GoBoard.png"));
	RESOURCES->Add<WTexture>(L"BlackStone", std::make_shared<WTexture>(L"BlackStone.png"));
	RESOURCES->Add<WTexture>(L"WhiteStone", std::make_shared<WTexture>(L"WhiteStone.png"));
	RESOURCES->Add<WTexture>(L"BlackStoneUI", std::make_shared<WTexture>(L"BlackStoneUI.png"));
	RESOURCES->Add<WTexture>(L"WhiteStoneUI", std::make_shared<WTexture>(L"WhiteStoneUI.png"));
	RESOURCES->Add<WTexture>(L"FourFourBan", std::make_shared<WTexture>(L"FourFourBan.png"));
	RESOURCES->Add<WTexture>(L"ThreeThreeBan", std::make_shared<WTexture>(L"ThreeThreeBan.png"));
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
	APP->Initialize(1000, 1000, L"Gomoku By GatsLee");

	ImportResources();

	CreateTitleScene();
	CreateGameScene();

	APP->Run();
}

