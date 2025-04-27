#include "Headers\pch.h"
#include "SceneManager.h"

void SceneManager::AddSceneToMap(const std::string& key, std::shared_ptr<Scene> scene)
{
	auto it = mSceneMap.find(key);
	if (it == mSceneMap.end())
	{
		mSceneMap[key] = scene;
	}
	else
	{
		DEBUG_PRINT_A1("SceneManager::AddScene | Scene already exists: %s", key.c_str());
	}
}

void SceneManager::RemoveSceneFromMap(const std::string& key)
{
	auto it = mSceneMap.find(key);
	if (it != mSceneMap.end())
	{
		mSceneMap.erase(it);
	}
	else
	{
		DEBUG_PRINT_A1("SceneManager::RemoveScene | Scene not found: %s", key.c_str());
	}
}

void SceneManager::ClearSceneMap()
{
	mSceneMap.clear();
}

void SceneManager::PushScene(const std::string& key)
{
	auto scene = GetScene(key);
	if (!scene) return;

	if (!mSceneStack.empty())
	{
		mSceneStack.back()->OnExit();
	}

	mSceneStack.push_back(scene);
	scene->OnEnter();
}

void SceneManager::ChangeScene(const std::string& key)
{
	while (!mSceneStack.empty())
	{
		mSceneStack.back()->OnExit();
		mSceneStack.pop_back();
	}

	auto scene = GetScene(key);
	if (scene)
	{
		mSceneStack.push_back(scene);
		scene->OnEnter();
	}
	else
	{
		DEBUG_PRINT_A1("SceneManager::ChangeScene | Scene not found: %s", key.c_str());
	}
}

void SceneManager::PopScene()
{
	if (!mSceneStack.empty())
	{
		mSceneStack.back()->OnExit();
		mSceneStack.pop_back();
		if (!mSceneStack.empty())
		{
			mSceneStack.back()->OnEnter();
		}
	}
	else
	{
		DEBUG_PRINT_A1("SceneManager::PopScene | No scene to pop.");
	}
}

void SceneManager::ReloadScene(const std::string& key)
{
	auto it = mSceneMap.find(key);
	if (it != mSceneMap.end())
	{
		if (!mSceneStack.empty())
		{
			mSceneStack.back()->OnExit();
			mSceneStack.back()->OnEnter();
		}
	}
	else
	{
		DEBUG_PRINT_A1("SceneManager::ReloadScene | Scene not found: %s", key.c_str());
	}
}

void SceneManager::ClearSceneStack()
{
	while (!mSceneStack.empty())
	{
		mSceneStack.back()->OnExit();
		mSceneStack.pop_back();
	}
	DEBUG_PRINT_A1("SceneManager::ClearSceneStack | All scenes cleared.");
}

void SceneManager::UpdateCurrentScene()
{
	if (!mSceneStack.empty())
	{
		mSceneStack.back()->Update();
	}
	else
	{
		DEBUG_PRINT_A1("SceneManager::UpdateCurrentScene | No current scene set.");
	}
}

void SceneManager::RenderCurrentScene()
{
	if (!mSceneStack.empty())
	{
		mSceneStack.back()->Render();
	}
	else
	{
		DEBUG_PRINT_A1("SceneManager::RenderCurrentScene | No current scene set.");
	}
}
