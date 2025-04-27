#include "Headers/pch.h"
#include "TimeManager.h"

void TimeManager::Initialize()
{
	::QueryPerformanceFrequency(reinterpret_cast<LARGE_INTEGER*>(&mFrequency));
	::QueryPerformanceCounter(reinterpret_cast<LARGE_INTEGER*>(&mPrevTick));
}

void TimeManager::Update()
{
	uint64 currentTick;
	::QueryPerformanceCounter((LARGE_INTEGER*)&currentTick);

	mDeltaTime = (currentTick - mPrevTick) / static_cast<float>(mFrequency);
	mPrevTick = currentTick;

	mFrameCount++;
	mFrameTime += mDeltaTime;

	if (mFrameTime >= 1.0f)
	{
		mFps = static_cast<uint32>(mFrameCount / mFrameTime);
		mFrameTime = 0.0f;
		mFrameCount = 0;
	}
}