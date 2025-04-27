#include "Headers/pch.h"
#include "Scene.h"
#include "Component/Camera.h"

Scene::Scene(std::string sceneName)
{
	mSceneName = sceneName;
};

Scene::~Scene()
{}

void Scene::DefaultInitialize()
{
	for (auto& [name, object] : mGameObjects)
	{
		object->Awake();
		object->Start();
	}
	CreateDefaultCamera();
}

void Scene::DefaultUpdate()
{
	for (auto& [name, object] : mGameObjects)
	{
		object->Update();
	}
	for (auto& [name, object] : mUIObjects)
	{
		object->Update();
	}
}

void Scene::DefaultRender()
{
	for (auto& [name, object] : mGameObjects)
	{
		object->Render();
	}
	for (auto& [name, object] : mUIObjects)
	{
		object->Render();
	}

}

void Scene::CreateDefaultCamera()
{
	mDefaultCamera = std::make_shared<GameObject>(L"DefaultCamera");
	auto windowSize = APP->GetWindowSize();
	mDefaultCamera->AddComponent(std::make_shared<Camera>(sf::FloatRect( sf::Vector2f(0.f, 0.f),
																sf::Vector2f(windowSize.x, windowSize.y) )));
	mDefaultCamera->GetCamera()->SetCenter(windowSize.x / 2.f, windowSize.y / 2.f);
	WINDOW->setView(mDefaultCamera->GetCamera()->GetNativeCamera());
}

void Scene::AddGameObject(const std::wstring& name, std::shared_ptr<GameObject> object)
{
	auto iter = mGameObjects.find(name);
	if (iter == mGameObjects.end())
	{
		mGameObjects[name] = object;
	}
	else
	{
		DEBUG_PRINT_W1(L"GameObject with name %s already exists", name.c_str());
	}
}

void Scene::RemoveGameObject(const std::wstring& name)
{
	auto iter = mGameObjects.find(name);
	if (iter != mGameObjects.end())
	{
		mGameObjects.erase(iter);
	}
	else
	{
		DEBUG_PRINT_W1(L"GameObject with name %s does not exist", name.c_str());
	}
}

std::shared_ptr<GameObject> Scene::GetGameObject(const std::wstring& name)
{
	auto iter = mGameObjects.find(name);
	if (iter != mGameObjects.end())
	{
		return iter->second;
	}
	else
	{
		DEBUG_PRINT_W1(L"GameObject with name %s does not exist", name.c_str());
		return nullptr;
	}
}

void Scene::AddUIWidget(const std::wstring& name, std::shared_ptr<UIWidget> object)
{
	auto iter = mUIObjects.find(name);
	if (iter == mUIObjects.end())
	{
		mUIObjects[name] = object;
	}
	else
	{
		DEBUG_PRINT_W1(L"UIWidget with name %s already exists", name.c_str());
	}
}

void Scene::RemoveUIWidget(const std::wstring& name)
{
	auto iter = mUIObjects.find(name);
	if (iter != mUIObjects.end())
	{
		mUIObjects.erase(iter);
	}
	else
	{
		DEBUG_PRINT_W1(L"UIWidget with name %s does not exist", name.c_str());
	}
}

std::shared_ptr<UIWidget> Scene::GetUIWidget(const std::wstring& name)
{
	auto iter = mUIObjects.find(name);
	if (iter != mUIObjects.end())
	{
		return iter->second;
	}
	else
	{
		DEBUG_PRINT_W1(L"UIWidget with name %s does not exist", name.c_str());
		return nullptr;
	}
}
