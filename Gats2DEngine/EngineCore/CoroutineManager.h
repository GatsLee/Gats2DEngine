#pragma once
class CoroutineManager
{
	DECLARE_SINGLE(CoroutineManager)
public:
    void Initialize();

    void Update();

    void StartCoroutine(float waitTime, std::function<void()> callback);

private:
    struct Task {
        float elapsed = 0.f;
        float duration = 0.f;
        std::function<void()> callback;

        bool Update() {
            elapsed += DT;
            if (elapsed >= duration) {
                if (callback) callback();
                return true;
            }
            return false;
        }
    };

    std::vector<Task> mCoroutineList;
};

