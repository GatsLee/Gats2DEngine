#include "Headers\pch.h"
#include "Animation.h"
#include "Resource/WTexture.h"

Animation::Animation()
	: ResourceBase(ResourceType::Animation)
{
	mName = L"DefaultAnimation";
}

Animation::Animation(std::wstring name, std::shared_ptr<sf::Sprite> sprite, int rows, int cols, float duration)
	: ResourceBase(ResourceType::Animation)
{
	mName = name;
	mSprite = sprite;
	if (!mSprite)
	{
		ASSERT_MSG(false, "Sprite is null");
	}
	mFrameCount = rows * cols;
	mFrames.resize(mFrameCount);

	// Auto Framing
	if (rows <= 0 || cols <= 0)
	{
		ASSERT_MSG(false, "Invalid rows or cols");
	}
	sf::Vector2f frameSize = mSprite->getGlobalBounds().size;
	int frameWidth = static_cast<int>(frameSize.x / cols);
	int frameHeight = static_cast<int>(frameSize.y / rows);
	float avgFrameDuration = duration / mFrameCount;
	for (int row = 0; row < rows; ++row)
	{
		for (int col = 0; col < cols; ++col)
		{
			int index = row * cols + col;
			mFrames[index].rect = sf::IntRect(sf::Vector2(col * frameWidth, row * frameHeight), 
												sf::Vector2(frameWidth, frameHeight));
			mFrames[index].duration = avgFrameDuration;
			mFrames[index].elapsedTime = 0.f;
		}
	}

}

Animation::Animation(std::wstring name, std::shared_ptr<sf::Sprite> sprite, const std::vector<sf::IntRect>& frames, float duration)
	: ResourceBase(ResourceType::Animation)
{
	mName = name;
	mSprite = sprite;
	if (!mSprite)
	{
		assert(false && "Sprite is null");
	}
	mFrameCount = frames.size();
	mFrames.resize(mFrameCount);
	mTotalDuration = duration;
	mAvgFrameDuration = mTotalDuration / mFrameCount;
	for (int i = 0; i < mFrameCount; ++i)
	{
		mFrames[i].rect = sf::IntRect(frames[i]);
		mFrames[i].duration = mAvgFrameDuration;
		mFrames[i].elapsedTime = 0.f;
	}
}

Animation::~Animation()
{
}

void Animation::Update()
{
	if (mFrameCount == 0)
	{
		return;
	}
	mFrames[mCurrentFrame].elapsedTime += DT;
	if (mFrames[mCurrentFrame].elapsedTime >= mFrames[mCurrentFrame].duration)
	{
		mFrames[mCurrentFrame].elapsedTime = 0.f;
		mCurrentFrame++;
		if (mCurrentFrame >= mFrameCount)
		{
			if (mLoop)
			{
				mCurrentFrame = 0;
			}
			else
			{
				mCurrentFrame = mFrameCount - 1; // stay on the last frame
			}
		}
	}
	mSprite->setTextureRect(mFrames[mCurrentFrame].rect);
}

void Animation::Reset()
{
	mCurrentFrame = 0;
	for (int i = 0; i < mFrameCount; ++i)
	{
		mFrames[i].elapsedTime = 0.f;
	}
	mSprite->setTextureRect(mFrames[mCurrentFrame].rect);
}

void Animation::AddFrame(const sf::IntRect& rect, float unitDuration)
{
	if (mFrameCount >= MAX_ANIMATION_FRAME)
	{
		assert(false && "Max frame count reached");
		return;
	}
	mFrames.push_back({ rect, unitDuration, 0.f });
	mFrameCount++;
	mTotalDuration += unitDuration;
	mAvgFrameDuration = mTotalDuration / mFrameCount;
}
