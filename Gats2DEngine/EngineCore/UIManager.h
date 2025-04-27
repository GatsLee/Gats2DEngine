#pragma once
class UIManager
{
	DECLARE_SINGLE(UIManager)
public:
    void Update()
    {
		if (mUILockTime > 0.f)
		{
			mUILockTime -= DT;
			if (mUILockTime < 0.f)
				mUILockTime = 0.f;
		}



        mInputConsumed = false;

		if (IsUILocked())
			return;

		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
		{
			mInputConsumed = true;
		}
    }

	bool IsInputConsumed() const { return mInputConsumed; }
	void ConsumeInput() { mInputConsumed = true; }
	void ResetInput() { mInputConsumed = false; }

	void LockUI(float duration = 0.1f) { mUILockTime = duration; }
	bool IsUILocked() const { return mUILockTime > 0.f; }
private:
	bool mInputConsumed = false;
	float mUILockTime = 0.f;
};

