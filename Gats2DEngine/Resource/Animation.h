#pragma once
#include "ResourceBase.h"

struct FrameData
{
	sf::IntRect rect;
	float duration = 0.f; // duration per frame
	float elapsedTime = 0.f; // time passed after this frame started
};

class Animation : public ResourceBase
{
public:
	Animation();
	Animation(std::wstring name, std::shared_ptr<sf::Sprite> sprite, int rows, int cols, float duration);
	Animation(std::wstring name, std::shared_ptr<sf::Sprite> sprite, const std::vector<sf::IntRect>& frames, float duration);
	~Animation();

	void Update();
	void Reset();

	void AddFrame(const sf::IntRect& rect, float duration = 0.f);
	void SetSprite(std::shared_ptr<sf::Sprite> sprite) { mSprite = sprite; }
	void SetLoop(bool loop) { mLoop = loop; }

	FrameData& GetFrame(int index) { return mFrames[index]; }
	FrameData& GetCurrentFrame() { return mFrames[mCurrentFrame]; }
	std::shared_ptr<sf::Sprite> GetSprite() { return mSprite; }

private:
	int mFrameCount = 0; // number of frames
	int mCurrentFrame = 0; // current frame index
	float mTotalDuration = 0.f; // total duration of the animation
	float mAvgFrameDuration = 0.f; // average duration per frame
	bool mLoop = false; // whether the animation should loop

	std::vector<FrameData> mFrames; // vector seq is same as animation seq
	std::vector<float> mFrameDurations; // duration of each frame(cached for performance)
	std::shared_ptr<sf::Sprite> mSprite;
};

