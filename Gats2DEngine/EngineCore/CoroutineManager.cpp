#include "Headers\pch.h"
#include "CoroutineManager.h"

void CoroutineManager::Initialize()
{
	mCoroutineList.clear();
	mCoroutineList.reserve(100);
}

void CoroutineManager::Update()
{
	for (auto it = mCoroutineList.begin(); it != mCoroutineList.end();)
	{
		if (it->Update())
		{
			it = mCoroutineList.erase(it);
		}
		else
		{
			++it;
		}
	}
}

void CoroutineManager::StartCoroutine(float waitTime, std::function<void()> callback)
{
	mCoroutineList.emplace_back(Task{ 0.f, waitTime, callback });
}
