#pragma once

// lib
#pragma comment(lib, "freetype.lib")
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "winmm.lib")
#pragma comment(lib, "gdi32.lib")
#pragma comment(lib, "user32.lib")
#pragma comment(lib, "advapi32.lib")
#pragma comment(lib, "ws2_32.lib")
#pragma comment(lib, "ole32.lib")
#pragma comment(lib, "shell32.lib")
#pragma comment(lib, "version.lib")
#pragma comment(lib, "comdlg32.lib")

#ifdef _DEBUG
	#pragma comment(lib, "sfml-graphics-s-d.lib")
	#pragma comment(lib, "sfml-window-s-d.lib")
	#pragma comment(lib, "sfml-system-s-d.lib")
	#pragma comment(lib, "sfml-audio-s-d.lib")
	#pragma comment(lib, "sfml-network-s-d.lib")
#else
	#pragma comment(lib, "sfml-graphics-s.lib")
	#pragma comment(lib, "sfml-window-s.lib")
	#pragma comment(lib, "sfml-system-s.lib")
	#pragma comment(lib, "sfml-audio-s.lib")
	#pragma comment(lib, "sfml-network-s.lib")
#endif

#include "Types.h"
#include "Define.h"

// STL
#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <array>
#include <deque>
#include <unordered_map>
#include <string>
#include <memory>
#include <algorithm>
#include <filesystem>

//SFML
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>


#include "EngineCore/Application.h"
#include "EngineCore/Scene.h"
#include "EngineCore/SceneManager.h"
#include "EngineCore/InputManager.h"
#include "EngineCore/ResourceManager.h"
#include "EngineCore/TimeManager.h"
#include "EngineCore/EventManager.h"
#include "EngineCore/CoroutineManager.h"
#include "EngineCore/UIManager.h"
#include "GameObject/GameObject.h"
#include "Resource/ResourceBase.h"
#include "Resource/Animation.h"
#include "Resource/Material.h"
#include "Resource/WTexture.h"
#include "Resource/WFont.h"
#include "Resource/WShader.h"

#include "Component/Component.h"
#include "Component/SpriteRenderer.h"
#include "Component/Animator.h"
#include "Component/Camera.h"
#include "Component/Transform2D.h"
#include "Component/ScriptComponent.h"

#include "UI/UIWidget.h"
#include "UI/UIPanel.h"
#include "UI/UILabel.h"
#include "UI/UIImage.h"
#include "UI/UIButton.h"
