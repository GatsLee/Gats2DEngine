#pragma once


class SceneManager
{
	DECLARE_SINGLE(SceneManager);
public:
	// scene map: total scenes
    void AddSceneToMap(const std::string& key, std::shared_ptr<Scene> scene);
    void RemoveSceneFromMap(const std::string& key);
    void ClearSceneMap();

	// scene stack: active scenes(or subscenes)
    void PushScene(const std::string& key);
	void PopScene(); // pop current scene: pause menu
	void ChangeScene(const std::string& key); // pop current scene and push new scene : full scene switch
    void ReloadScene(const std::string& key);
	void ClearSceneStack();

    void UpdateCurrentScene();
    void RenderCurrentScene();

    std::shared_ptr<Scene> GetCurrentScene()
    { 
		if (mSceneStack.empty())
		{
			return nullptr;
		}
		return mSceneStack.back();
    }
    std::shared_ptr<Scene> GetScene(const std::string& type)
    {
        auto it = mSceneMap.find(type);
        if (it != mSceneMap.end())
        {
            return it->second;
        }
        return nullptr;
    }

private:
    std::unordered_map<std::string, std::shared_ptr<Scene>> mSceneMap;
    std::deque<std::shared_ptr<Scene>> mSceneStack;
};
