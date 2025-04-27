#pragma once

class TimeManager
{
	DECLARE_SINGLE(TimeManager)
public:
	void Initialize();
	void Update();

	uint32 GetFps() const { return mFps; }
	float GetDeltaTime() const { return mDeltaTime; }

private:
	uint64 mFrequency = 0;
	uint64 mPrevTick = 0;
	float mDeltaTime = 0.0f;

private:
	uint32 mFps = 0;
	float mFrameTime = 0.0f;
	uint32 mFrameCount = 0;
};
