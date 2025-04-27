#pragma once

#include "Scene.h"

class Application
{
	DECLARE_SINGLE(Application);
public:

	void Initialize(UINT width = 1080, UINT height = 1080, std::wstring appName = L"Default Title");
	void Run();

	sf::RenderWindow* GetWindow() { return mWindow.get(); }

	const sf::Vector2i& GetWindowSize() { return sf::Vector2i(mWindowWidth, mWindowHeight); }

private:
	void Update();

private:
	void CreateWindowSFML();
	void ProcessEvents();
	
private:
	// SFML Objects
	std::unique_ptr<sf::RenderWindow> mWindow = nullptr;

	// Window description
	std::wstring mAppName = L"Default Title";
	UINT mWindowWidth = 1080;
	UINT mWindowHeight = 1080;

	// System Flags
	bool IsRunning = true;
};

