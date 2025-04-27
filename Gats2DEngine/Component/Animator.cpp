#include "Headers\pch.h"
#include "Animator.h"
#include "Resource/Animation.h"

Animator::Animator() : Component(ComponentType::Animator)
{
}

Animator::~Animator()
{
}

void Animator::PlayAnimation(const std::string& name)
{
	if (mAnimations.count(name) == 0)
		return;

	if (mCurrentAnimation != mAnimations[name])
	{
		mCurrentAnimation = mAnimations[name];
		mCurrentAnimation->Reset();
	}
	mIsPaused = false;
}

void Animator::PauseAnimation(const std::string& name)
{
	if (mCurrentAnimation && mAnimations[name] == mCurrentAnimation)
		mIsPaused = true;
}

void Animator::StopAnimation(const std::string& name)
{
	if (mCurrentAnimation && mAnimations[name] == mCurrentAnimation)
	{
		mCurrentAnimation->Reset();
		mCurrentAnimation = nullptr;
	}
}

void Animator::Update()
{
	if (mCurrentAnimation && !mIsPaused)
	{
		mCurrentAnimation->Update();
		mCurrentAnimation->GetSprite()->setTextureRect(mCurrentAnimation->GetCurrentFrame().rect);
	}
}


void Animator::Render()
{
	if (mCurrentAnimation)
	{
		WINDOW->draw(*mCurrentAnimation->GetSprite());
	}
}
