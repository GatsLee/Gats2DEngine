#pragma once
#include "Component.h"

class Animation;

class Animator : public Component
{
public:
	Animator();
	~Animator();

	void PlayAnimation(const std::string& name);
	void PauseAnimation(const std::string& name);
	void StopAnimation(const std::string& name);
	void Update() override;
	void Render() override;

private:
	std::unordered_map<std::string, std::shared_ptr<Animation>> mAnimations;
	std::shared_ptr<Animation> mCurrentAnimation;
	bool mIsPaused = false;
};

