#include "Headers/pch.h"
#include "Application.h"

void Application::Initialize(UINT width, UINT height, std::wstring title)
{
	mWindowWidth = width;
	mWindowHeight = height;
	mAppName = title;
	CreateWindowSFML();

	// Initialize Managers
	RESOURCES->Initialize();
	TIME->Initialize();
	INPUT->Initialize();
	COROUTINE->Initialize();
}

void Application::Run()
{
	IsRunning = true;
	// Main Loop
	while (IsRunning && mWindow->isOpen())
	{
		ProcessEvents();
		Update();
	}
}

void Application::Update()
{
	mWindow->clear(sf::Color::White);
	TIME->Update();
	INPUT->Update();
	COROUTINE->Update();
	UI->Update();

	SCENE->UpdateCurrentScene();
	SCENE->RenderCurrentScene();

	mWindow->display();
}

void Application::CreateWindowSFML()
{
	sf::VideoMode mode({ mWindowWidth, mWindowHeight });

	// Create Window
	mWindow = std::make_unique<sf::RenderWindow>(mode, mAppName, sf::Style::Default);
	mWindow->setVerticalSyncEnabled(true);
}

void Application::ProcessEvents()
{
	while (const std::optional event = mWindow->pollEvent())
	{
		if (event->is<sf::Event::Closed>())
		{
			mWindow->close();
			IsRunning = false;
		}
	}
}

