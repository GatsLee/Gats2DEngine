#pragma once
#include "Component\ScriptComponent.h"
class FadeScript : public Script
{
public:
    enum class FadeType
    {
        FadeIn,
        FadeOut
    };

    FadeScript(FadeType type, float duration)
        : mFadeType(type), mDuration(duration)
    {
    }

    virtual void Start() override
    {
        mElapsed = 0.f;
        mSpriteRenderer = GetOwner()->GetSpriteRenderer();
    }

    virtual void Update() override
    {
        if (!mSpriteRenderer)
            return;

        mElapsed += DT;

        float t = min(mElapsed / mDuration, 1.f); // Clamp between 0 ~ 1

        uint8_t alpha = 255;

        if (mFadeType == FadeType::FadeIn)
        {
            alpha = static_cast<uint8_t>(255.f * t); // 0 ¡æ 255
        }
        else if (mFadeType == FadeType::FadeOut)
        {
            alpha = static_cast<uint8_t>(255.f * (1.f - t)); // 255 ¡æ 0
        }

        // Set the color with new alpha
        sf::Color color = mSpriteRenderer->GetColor();
        color.a = alpha;
        mSpriteRenderer->SetColor(color);

        if (t >= 1.f && !mCompleted)
        {
            mCompleted = true;

            if (mOnFadeComplete)
                mOnFadeComplete();
        }
    }

    void SetOnFadeComplete(std::function<void()> callback)
    {
        mOnFadeComplete = callback;
    }

private:
    FadeType mFadeType;
    float mDuration = 1.f; // Fade total time
    float mElapsed = 0.f; // How much time passed
    bool mCompleted = false;

    std::function<void()> mOnFadeComplete = nullptr;

    std::shared_ptr<SpriteRenderer> mSpriteRenderer = nullptr;
};

